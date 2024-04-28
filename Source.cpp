#include<iostream>
#include<fstream>
using namespace std;
bool search_Right(char** array, int size, char word[]) {
	int i = 0;
	bool found = 0;
	for (int r = 0; r < size; r++) {
		for (int c = 0; c < size; c++) {
			if (array[r][c] == word[i]) {
				for (int k = c; word[i] != '\0'; k++) {
					if (array[r][k] == word[i]) {
						i++;
						found = 1;
					}
					else {
						i++;
						found = 0;
						break;
					}
				}
			}
			if (found == 1) {
				return 1;
			}
			if (found == 0) {
				i = 0;
			}
		}
	}
	return 0;
}
bool search_Down(char** array, int size, char word[]) {
	int i = 0;
	bool found = 0;
	for (int c = 0; c < size; c++) {
		for (int r = 0; r < size; r++) {
			if (array[r][c] == word[i]) {
				for (int k = r; word[i] != '\0'; k++) {
					if (k >= size) {
						i = 0;
						found = 0;
						break;
					}
					if (array[k][c] == word[i]) {
						i++;
						found = 1;
					}
					else {
						i = 0;
						found = 0;
						break;
					}
				}
			}
			if (found == 1) {
				return 1;
			}
		}
	}
	return 0;
}
bool search_Up(char** array, int size, char word[]) {
	int i = 0;
	bool found = 0;
	for (int c = size - 1; c >= 0; c--) {
		for (int r = size - 1; r >= 0; r--) {
			if (array[r][c] == word[i]) {
				for (int k = r; word[i] != '\0'; k--) {
					if (array[k][c] == word[i]) {
						i++;
						found = 1;
					}
					else {
						i = 0;
						found = 0;
						break;
					}
				}
			}
			if (found == 1) {
				return 1;
			}
		}
	}
	return 0;
}
bool search_Left(char** array, int size, char word[]) {
	int i = 0;
	bool found = 0;
	for (int r = size - 1; r >= 0; r--) {
		for (int c = size - 1; c >= 0; c--) {
			if (array[r][c] == word[i]) {
				for (int k = c; word[i] != '\0'; k--) {
					if (array[r][k] == word[i]) {
						i++;
						found = 1;
					}
					else {
						i++;
						found = 0;
						break;
					}
				}
			}
			if (found == 1) {
				return 1;
			}
			if (found == 0) {
				i = 0;
			}
		}
	}
	return 0;
}
void displayMenu(char& opt)
{
	do
	{
		cout << "[-]____WELCOME TO WORD SEARCH PUZZLE_____[-]" << endl;
		cout << "\t\tPRESS (N) TO START A NEW GAME:" << endl;
		cout << "\t\tPRESS (E) TO EXIT GAME" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> opt;
		cout << endl;
	} while (opt != 'N' && opt != 'e' && opt != 'E'  && opt != 'n');
	 
}
void selectlevel(int& level, char** array, int size, char word[])
{
	do
	{
		cout << "SELECT LEVELS:" << endl;
		cout << "PRESS (0) FOR EASY LEVEL" << endl;
		cout << "PRESS (1) FOR HARD LEVEL" << endl;
		cout << "ENTER YOUR OPTION: ";
		cin >> level;
		if (level == 0)
		{
			cout << endl;
			cout << "          EASY LEVEL" << endl;
			cout << "[-]__________[-]" << endl;
			search_Right(array, size, word);
			search_Down(array, size, word);
		}
		else if (level == 1)
		{
			cout << endl;
			cout << "       INTERMEDIATE LEVEL!!" << endl;
			cout << "[-]__________[-]" << endl;
			search_Up(array, size, word);
			search_Down(array, size, word);
			search_Right(array, size, word);
			search_Left(array, size, word);
		}
	} while (level != 0 && level != 1);
}
void read_board(char** board, int rows, int cols)
{
	ifstream fin("data.txt");
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			fin >> board[r][c];
		}
	}
	fin.close();
}
void displayPuzzle(int rows, int cols, char** board)
{
	read_board(board, rows, cols);
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			cout << board[r][c] << " ";
		}cout << endl;
	}
}
void zeroinput(char(&arr)[15])
{
	for (int i = 0; i < 15; i++) {
		arr[i] = '0';
	}
}
void write_Borad_in_File(int rows, int cols, char** board)
{
	ofstream fout("pausegame.txt");
	for (int r = 0; r < rows; r++)
	{
		for (int c = 0; c < cols; c++)
		{
			fout << board[r][c] << " ";
		}fout << endl;
	}
}
void name_input(char name[15])
{
	cout << "PLEASE ENTER YOUR NAME: ";
	cin >> name;
}
void clearinput(char(&input)[15])
{
	for (int i = 0; i < 15; i++) {
		input[i] = '\0';
	}
}
int main()
{
	int rows = 15, cols = 15;
	char** puzzle = new char* [rows];
	for (int i = 0; i < rows; i++)
	{
		puzzle[i] = new char[cols];
	}
	char choice = 0;
	ifstream fin, fin1;
	int level = 0, life = 2, score = 0;
	char word[15] = { 0 };
	zeroinput(word);
	char name[20] = { "\0" };
	ofstream fout;

	displayMenu(choice);
	if (choice == 'N' || choice == 'n') {
		name_input(name);
		selectlevel(level, puzzle, rows, word);
		read_board(puzzle, rows, cols);
		do
		{
			displayPuzzle(rows, cols, puzzle);
			cout << "[-]_______[-]" << endl;
			cout << "PRESS (H) FOR RECORDS" << endl;
			cout << "PRESS (P) FOR PAUSE THE GAME" << endl;
			cout << "PRESS (E) FOR EXIT THE GAME" << endl;
			cout << "[-]__________[-]" << endl;
			clearinput(word);
			cout << "[-]YOUR " << life << " LIFES ARE LEFT!!" << endl;
			cout << "[-]YOUR SCORE IS: " << score << endl;
			cout << "ENTER A WORD YOU WANT TO FIND: ";
			cin >> word;
			cout << "[-]____________[-]" << endl;
			if (level == 0) {
				if (search_Right(puzzle, rows, word) || search_Down(puzzle, rows, word)) {
					score += 10;
				}
				else {
					life--;
				}
			}
			else if (level == 1) {
				if (search_Up(puzzle, rows, word) || search_Right(puzzle, rows, word) || search_Left(puzzle, rows, word) || search_Down(puzzle, rows, word)) {
					score += 10;
				}
				else {
					life--;
				}
			}
			fout.open("records.txt", ios::app);
			fout << "NAME: " << name << " " << " SCORE: " << score << endl;
			//cout << name << endl;
			fout.close();
			if (word[0] == 'e' && word[1] == '\0')
			{
				cout << "GAME IS EXITING!!" << endl;
			}
			else if (word[0] == 'p' || word[0] == 'P' && word[1] == '\0')
			{
				cout << "[-]___PRESS (R) TO RESUME____[-]" << endl;
				write_Borad_in_File(rows, cols, puzzle);
				char resume = { '\0' };
				do
				{
					cin >> resume;
				} while (resume != 'r' && resume != 'R');
				word[1] = 'p';
			}
			else if (word[0] == 'h' || word[0] == 'H')
			{
				char rec[50] = {};
				cout << "HIGH SCORES ARE:  " << endl;
				ifstream fin3("records.txt");
				for (int i = 0; i < 3; i++)
				{
					fin3.getline(rec, 50);
					cout << rec << endl;
				}
				fin3.close();
				life = life + 1;
			}
			
			if (life == 0)
			{
				cout <<"life ="<< life;

				cout << "[-]___GAME OVER!!_____[-]" << endl;
			}


		} while (life > 0 && (word[0] != 'e'|| word[0] != 'E' ));
	}
	
	else if (choice == 'e' || choice == 'E')
	{
		cout << "[-]_____GAME ENDED!!_____[-]" << endl;
	}
	cout << "[-]____THANKS FOR PLAYING!!______[-]\n";
	system("pause");
	return 0;
}