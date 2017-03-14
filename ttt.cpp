//Stephen Orsino
//Max Walters
//Nishant Thomas
//July 7, 2016
//ttt.cpp

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include "ttt.h"
using namespace std;

//Setter
void TicTacToe::SetWinner(int tempwin)
{
	currentWinner = tempwin;
}
//Getter
int TicTacToe::GetWinner()
{
	return currentWinner;
}

//Return type: void
//Parameters: 3 players
//Purpose: To reset the game board back to default and scores to 0 
void TicTacToe::ResetMatch(Player &p1, Player &p2, Player &tg)
{
	//set game board to its initial values
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';
	//set Players current scores to 0
	p1.currentScore = 0;
	p2.currentScore = 0;
	tg.currentScore = 0;

}

//Return type: void
//Parameters: none
//Purpose: Resets board values 
void TicTacToe::ResetGame()
{
	//saet game board to its initial values
	board[0][0] = '1';
	board[0][1] = '2';
	board[0][2] = '3';
	board[1][0] = '4';
	board[1][1] = '5';
	board[1][2] = '6';
	board[2][0] = '7';
	board[2][1] = '8';
	board[2][2] = '9';

}

//Return Type: void
//Parameters: none
//Purpose: to display the current game board
void TicTacToe::DisplayBoard()
{
	cout << endl << endl;
	cout << "\t" << ' ' << board[0][0] << '|' << ' ' << board[0][1] << ' ' << '|' << ' ' << board[0][2] << ' ' << endl << endl;
	cout << "\t" << "---------\n";
	cout << "\t" << ' ' << board[1][0] << '|' << ' ' << board[1][1] << ' ' << '|' << ' ' << board[1][2] << ' ' << endl << endl;
	cout << "\t" << "---------\n";
	cout << "\t" << ' ' << board[2][0] << '|' << ' ' << board[2][1] << ' ' << '|' << ' ' << board[2][2] << ' ' << endl << endl;
	cout << endl << endl;
}

//Return Type: void
//Parameters: 1 Player, 1 int
//Purpose: to prompt the user to choose a space and validates that the space is 
//         not already taken.  Increments the activePlayer counter.
void TicTacToe::ChoosePosition(Player templayer, int &aPlayer)
{
	//declare local variables
	char space = ' ';
	bool isOpen = false;

	
	DisplayBoard();
	{
		//prompt for space
		cout << templayer.name << ", choose your next space: ";
		cin >> space;
		//nested for loop to check through board for the space and make it equal to playersymbol
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (space == board[i][j])
				{
					board[i][j] = templayer.symbol;
					aPlayer++;
					isOpen = true;
				}
			}
		}
		//alert player to space being already taken
		if (isOpen == false)
		{
			cout << "That space is not available.\n";
			system("read -n 1 -p \"Press any key to choose again.\"" );
		}
		isOpen = false;
	}
	system("clear");
}

//Return Type: void
//Parameters: 3 Players
//Purpose: To display the current score
void TicTacToe::DisplayScore(Player p1, Player p2, Player tg)
{
	cout << "\n-----------------------------------\n";
	cout << "\n\tThe Current Score:\n";
	cout << left << setw(25) << p1.name << "\t" << p1.currentScore << endl;
	cout << left << setw(25) << p2.name << "\t" << p2.currentScore << endl;
	cout << left << setw(25) << "Tie Games" << "\t" << tg.currentScore << endl;
	cout << "\n-----------------------------------\n";
}

//Return Type: void
//Parameters: none
//Purpose: to prompt for and store the Players' names

void TicTacToe::CreatePlayer(Player &p1, Player &p2)
{

	system("clear");
	//Prompt player 1 for name
	cout << "\nPlayer one please enter your name: ";
	cin >> p1.name;

	//initialize player 1 score to 0
	p1.currentScore = 0;

	//set player 1 appropriate sybol
	p1.symbol = 'X';

	//Prompt player 2 for name
	cout << "\nPlayer two please enter your name: ";
	cin >> p2.name;

	//initialize player  2 score to 0
	p2.currentScore = 0;

	//set player 2 appropriate sybol
	p2.symbol = 'O';
	system("clear");


}

//Return Type: int
//Parameters: 1 bool 3 Player
//Purpose: after every move, checks the board for a winner or tie.  If there is a 
//         winner, returns an integer representing that winner and increments 
//         their score.  If its a tie, increments "TieGame".
int TicTacToe::CheckforWinner(bool &end, Player &p1, Player &p2, Player &tg)
{
	//check for 3 X in a row
	if ((board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') ||
		(board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X') ||
		(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') ||
		(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') ||
		(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') ||
		(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') ||
		(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
		(board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X'))
	{
		//if so, end game and increment player 1 score
		end = true;
		p1.currentScore++;
		return 1;
	}
	//check for 3 O in a row
	if ((board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') ||
		(board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O') ||
		(board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') ||
		(board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') ||
		(board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') ||
		(board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') ||
		(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
		(board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O'))
	{
		//if so, end game and increment player 2 score
		end = true;
		p2.currentScore++;
		return 2;
	}
	//check if all spaces are taken
	if ((board[0][0] == 'X' || board[0][0] == 'O') &&
		(board[0][1] == 'X' || board[0][1] == 'O') &&
		(board[0][2] == 'X' || board[0][2] == 'O') &&
		(board[1][0] == 'X' || board[1][0] == 'O') &&
		(board[1][1] == 'X' || board[1][1] == 'O') &&
		(board[1][2] == 'X' || board[1][2] == 'O') &&
		(board[2][0] == 'X' || board[2][0] == 'O') &&
		(board[2][1] == 'X' || board[2][1] == 'O') &&
		(board[2][2] == 'X' || board[2][2] == 'O'))
	{
		//if so, end game and increment tieGame score
		end = true;
		tg.currentScore++;
		return 0;
	}
}
