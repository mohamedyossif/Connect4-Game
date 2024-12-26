#include<iostream>
#include <cctype>
#include<array>
using namespace std;
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
				cout << "-----";

		}
		cout << endl;
		for (int j = 0; j < 8; j++)
		{
			if (i == 6 )
			{
				break;
				}
			else if (j==7)
			{
				cout << "|";
			}
			else
			{	
				// check if 2 digit don`t add 0 if one digit add 0 before num
				if (matrix[i][j] == '#' || matrix[i][j] == '%')
				{
					cout << "|  " << matrix[i][j] << " ";
				}
				else {
					int number = matrix[i][j] - '0';
					if (number > 9)
					{
						cout << "| " << number << " ";
					}
					else {
						cout << "|  " << number << " ";
					}
				}
				
			}
				
		}
		cout << endl;
	}
}
char checkWinner(char matrix[6][7])
{
	for (int i = 5; i > -1; --i) {

		for (int j = 0; j < 7; ++j) {
			int right = j + 4;
			bool primayDi = (j - 3 > -1) && (i - 3 > -1);
			bool secandaryDi = (j + 3 < 7) && (i - 3 > -1);
			if (right <= 7 )
			{
				if (matrix[i][j] == matrix[i][j + 1] && matrix[i][j + 1] == matrix[i][j + 2] && matrix[i][j + 2] == matrix[i][j + 3])
				{
					return matrix[i][j];
				}

				
			}

			if (i >= 3 )
			{
				if (matrix[i][j] == matrix[i-1][j] && matrix[i - 1][j] == matrix[i - 2][j] && matrix[i - 2][j] == matrix[i - 3][j])
				{
					return matrix[i][j];

				}
			}
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
array<int, 2> FindIndex(char matrix[6][7], int postion)
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			// Converts character digits to integer values using ASCII.
			// Subtracting '0' from the character converts it to the integer value by leveraging ASCII values. 
			int number = matrix[i][j] - '0';

			if (number == postion)
			{

				return  array<int, 2> {i, j};
			}


		}
		cout << endl;
	}
}
void main()
{	
	char matrix[6][7] ;
	int defValue = 1;
	for (int i = 5; i > -1; --i) {
		for (int j = 0; j < 7; ++j) {
			matrix[i][j] =defValue + '0';
			defValue++;
		}
	}
	
	int gameRounds = 0;
	int postion;
	char whoWinner;
	bool isHash = true;
	do {
		drowBoard(matrix);
		char XOrO = isHash ? '#' : '%';
		cout << "Enter postion from just 1 to 42  player " << XOrO << " : ";
		cin >> postion;
		//if user enter invalid number 
		while (postion < 1 || postion>42)
		{
			cout << "Invalid Value sir ,Plz Enter postion from just 1 to 9  player " << XOrO << " : ";
			cin >> postion;
		}
		array<int, 2>	arr = FindIndex(matrix, postion);
		cout << arr[0] << endl;
		
		while (arr[0]<5 && matrix[arr[0]+1][arr[1]]!= '#' && matrix[arr[0] +1][arr[1]]!='%')
		{
			cout << arr[0] - 1 << " " << arr[1] - 1 << endl;
			cout << "Invalid move! You must fill the lower slots in the column first." << XOrO << " : ";
			cin >> postion;
			arr = FindIndex(matrix, postion);
		}
		//store value in postion whihc user entered
		
		matrix[arr[0]][arr[1]] = XOrO;
		//To reduce the number of checkWinner operations from 9 to 6 and avoid unnecessary checks, 
			
			whoWinner = checkWinner(matrix);
			if (whoWinner == '#' || whoWinner == '%')
			{
				cout << "Winner is " << whoWinner << endl;
				drowBoard(matrix);
				break;
			}
		
		isHash = !isHash;
		gameRounds++;
		//clean console
		 system("cls");
	} while (gameRounds < 42);

	if (whoWinner != '#' && whoWinner != '%')
	{
		cout << "Game Over " << endl;
	}
}