#include<iostream>
#include <cctype>
#include<array>
using namespace std;
void initizalization(char matrix[6][7])
{
	for (int i = 5; i > -1; --i) {
		for (int j = 0; j < 7; ++j) {
			matrix[i][j] = ' ';

		}
	}
}
void drowBoard(char matrix[6][7])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i == 0)
			{
				break;
			}
			else if (j == 6)
			{
				cout << "-----";
			}
			else {
				cout << "----";
			}

		}
		cout << endl;
		for (int j = 0; j < 8; j++)
		{	// to ignore one line 
			if (i == 6)
			{
				break;
			}
			else if (j == 7)
			{
				cout << "|";
			}
			else
			{
				cout << "| " << matrix[i][j] << " ";
			}

		}
		cout << endl;
	}
	// draw 1 to 6 slot
	for (int i = 0; i < 7; i++)
	{
		cout<<"  " << i + 1<<" ";
	}
	cout << endl;
}
char checkWinner(char matrix[6][7])
{
	for (int i = 5; i > -1; --i) {

		for (int j = 0; j < 7; ++j) {

			int right = j + 4;
			
			bool primayDi = (j - 3 > -1) && (i - 3 > -1);
			bool secandaryDi = (j + 3 < 7) && (i - 3 > -1);
			//check right
			if (right <= 7)
			{
				if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j + 1] == matrix[i][j + 2] && matrix[i][j + 2] == matrix[i][j + 3])
				{
					return matrix[i][j];
				}
			}
			//check top
			if (i >= 3)
			{
				if (matrix[i][j] == matrix[i - 1][j] && matrix[i - 1][j] == matrix[i - 2][j] && matrix[i - 2][j] == matrix[i - 3][j])
				{
					return matrix[i][j];

				}
			}
			//check top
			if (primayDi)
			{
				if (matrix[i][j] == matrix[i - 1][j - 1] && matrix[i - 1][j - 1] == matrix[i - 2][j - 2] && matrix[i - 2][j - 2] == matrix[i - 3][j - 3])
				{
					return matrix[i][j];

				}
			}
			if (secandaryDi)
			{

				if (matrix[i][j] == matrix[i - 1][j + 1] && matrix[i - 1][j + 1] == matrix[i - 2][j + 2] && matrix[i - 2][j + 2] == matrix[i - 3][j + 3])
				{

					return matrix[i][j];
				}
			}
		}
	}

}
bool FindEmptySlot(char matrix[6][7], int slot,char value)
{
	for (int i = 5; i > -1; i--)
	{

		if (matrix[i][slot] == ' ')
		{
			matrix[i][slot] = value;
			return true;
		}

	}
	return false;
}
void main()
{
	char matrix[6][7];
	//initization
	initizalization(matrix);
	int gameRounds = 0;
	int slot;
	char whoWinner;
	bool isHash = true;
	bool isEmpty = true;
	do {
		drowBoard(matrix);
		char XOrO = isHash ? 'X' : 'O';
		cout << "Enter slot number from just 1 to 7  player " << XOrO << " : ";
		cin >> slot;
		bool isEmpty = FindEmptySlot(matrix, slot - 1, XOrO);
		//if user enter invalid number 
		while (slot < 1 || slot>7 || !isEmpty)
		{
			cout << "Invalid Value sir ,Plz Enter column from just 1 to 7  player " << XOrO << " : ";
			cin >> slot;
			isEmpty = FindEmptySlot(matrix, slot - 1, XOrO);
		}
	
		// avoid unnecessary checks, 
		if (gameRounds >= 6)
		{
			whoWinner = checkWinner(matrix);
			if (whoWinner == 'X' || whoWinner == 'O')
			{	
				cout << " \n \n Winner is " << whoWinner << endl;
				drowBoard(matrix);
				return;
			}
		}
		
		isHash = !isHash;
		gameRounds++;
		//clean console
		system("cls");
	} while (gameRounds < 42);

	if (whoWinner != 'X' && whoWinner != 'O')
	{
		cout << "Game Over " << endl;
	}
}