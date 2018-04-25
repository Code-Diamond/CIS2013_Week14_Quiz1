#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

class Game
{

private:

	string name;
	int score;

public:


	string getName()
	{
		return name;
	}
	int getScore()
	{
		return score;
	}
	void setScore(int inputScore)
	{
		score = inputScore;
	}
	void setName(string inputName)
	{
		name = inputName;
	}

};

class Minesweeper: public Game
{
private:
	int boardRows;
	int boardColumns;
	int bombSquares[20][20];
	char** board;

public:

	Minesweeper()
	{}

	Minesweeper(string inputName, int rows, int columns, int mines)
	{
		setName(inputName);
		boardRows = rows;
		boardColumns = columns;

		board = new char*[boardRows];
		for(int i = 0; i < boardColumns; i++)
		{
			board[i] = new char[boardColumns];
		}

		for(int i = 0; i < boardRows; i++)
		{
			for(int j = 0; j < boardColumns; j++)
			{
				board[i][j] = '+';
			}
		}
		//Set all bombSquares to 0
		for(int i = 0; i < 20; i++)
		{
			for(int j = 0; j < 20; j++)
			{
				bombSquares[i][j] = 0;
			}
		}
		//Set random bombSquares to 1
		for(int i = 0; i < mines; i++)
		{
			int currentLocationX = (rand() % rows);
			int currentLocationY = (rand() % columns);
			if(bombSquares[currentLocationX][currentLocationY] != 1)
			{
				bombSquares[currentLocationX][currentLocationY] = 1;	
			}
			else
			{
				i--;
			}
		}


	}

	void printBoard()
	{
		for(int i = 0; i < boardRows; i++)
		{
			for(int j = 0; j < boardColumns; j++)
			{
				cout << board[i][j] << " ";
			}
			cout << endl;
		}			
	}

	int getSquare(int x, int y)
	{
		return bombSquares[x][y];
	}

	void setBoardSquare(int x, int y)
	{
		board[x][y] = '0';
	}

};
int main()
{

	int rows, columns, mines;
	string name;

	cout << "Please enter your name: ";
	cin >> name;

	cout << "\n";

	cout << "Please enter the number of rows: ";
	cin >> rows;

	cout << "\n";

	cout << "Please enter the number of columns: ";
	cin >> columns;

	cout << "\n";

	cout << "Please enter the number of mines: ";
	cin >> mines;

	cout << "\n";

	Minesweeper obj(name, rows, columns, mines);

	cout << "Initial board" << endl;

	obj.printBoard();

	bool discovered = false;
	int x, y;
	while(!discovered)
	{
		cout << "Enter coordinates for sweeping." << endl;
		cout << "X: ";
		cin >> x;
		x = x - 1;
		cout << "Y: ";
		cin >> y;
		y = y - 1;
		if(obj.getSquare(x,y) == 1)
		{
			discovered = true;
			cout << "\n\n You discovered a bomb. \n\n";
		}
		else
		{
			obj.setBoardSquare(x,y);
			obj.printBoard();
		}
		
	}

	return 0;
}