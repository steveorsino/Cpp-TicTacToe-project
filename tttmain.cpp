//Stephen Orsino
//Max Walters
//Nishant Thomas
//July 7, 2016
//tttmain.cpp

#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include "ttt.cpp"
using namespace std;


int main()
{
	//declare variables
	TicTacToe game;
	char choice = ' ';
	Player player_1, player_2, tieGame;
	int activePlayer = 1;
	bool winner = false;
	int tracker = 0;

	//Intro
	cout << endl << endl;
	cout << "\txx      xx||          ||   ooo    \n";
	cout << "\t xx   xx  ||          || oo    oo \n";
	cout << "\t    xx    ||          ||oo      oo\n";
	cout << "\t xx   xx  ||          || oo    oo \n";
	cout << "\txx      xx||          ||    ooo   \n";
	cout << "\t__________________________________\n";
	cout << "\t__________________________________\n";
	cout << "\t          ||xx      xx||   ooo    \n";
	cout << "\t          || xx    xx || oo    oo \n";
	cout << "\t          ||     xx   ||oo      oo\n";
	cout << "\t          || xx    xx || oo    oo \n";
	cout << "\t          ||xx      xx||    ooo   \n";
	cout << "\t__________________________________\n";
	cout << "\t__________________________________\n";
	cout << "\t          ||          ||          \n";
	cout << "\t          ||          ||          \n";
	cout << "\t          ||          ||          \n";
	cout << "\t          ||          ||          \n";
	cout << "\tTicTacToe Battle!!!   ||          \n\n";
	
		//do while loop to run main program
	do {
		//diplay main menu
		cout << "1) Start a new match\n";
		cout << "2) Continue the current match\n";
		cout << "3) Exit\n";

		//prompt for choice
		cout << "Enter your choice: ";
		cin >> choice;

		system("clear");
		//Validates that a new match must be played before a match can be continued
		if (tracker == 0 && choice == '2')
		{
			system("clear");
			cout << "\nPlease start a new match before attempting to continue a match\n";
			//resets choice 
			choice = ' ';

		}

		if (choice == '1')
		{	
			//set winner back to false
			winner = false;
			//set active player back to 1 to ensure player 1 begins in a new match
			activePlayer = 1;
			//tracker incremented to allow players to continue match after this game
			tracker++; 
			//call function to reset match
			game.ResetMatch(player_1, player_2, tieGame);
			//call funcion to create player
			game.CreatePlayer(player_1, player_2);
			//do while loop to run game
			do
			{
				//check to see if player 1 is active
				if (activePlayer % 2 == 1)
				{
					//display board and player chooses space
					game.ChoosePosition(player_1, activePlayer);
					//if winning move or tie, winner is triggered
					game.SetWinner(game.CheckforWinner(winner, player_1, player_2, tieGame));
					if (winner)
					{
						if (game.GetWinner() == 1)
							cout << player_1.name << " wins!!!\n\n";
						else if (game.GetWinner() == 2)
							cout << player_2.name << " wins!!!\n\n";
						else
							cout << "This game is a tie...\n\n";
					}
				}
				//check to see if player 2 is active
				else if (activePlayer % 2 == 0)
				{
					//display board and player chooses space
					game.ChoosePosition(player_2, activePlayer);
					//if winning move or tie, winner is triggered
					game.SetWinner(game.CheckforWinner(winner, player_1, player_2, tieGame));
					if (winner)
					{
						if (game.GetWinner() == 1)
							cout << player_1.name << " wins!!!\n\n";
						else if (game.GetWinner() == 2)
							cout << player_2.name << " wins!!!\n\n";
						else
							cout << "This game is a tie...\n\n";
					}
				}
				//displays the score if winner was triggered
				if (winner == true)
					game.DisplayScore(player_1, player_2, tieGame);
			} while (winner == false);
		}
		else if (choice == '2')
		{
			//resets winner to false
			winner = false;
			//reset game
			game.ResetGame();
			//do while loop to run game
			do
			{
				//check to see if player 1 is active
				if (activePlayer % 2 == 1)
				{
					//display board and player chooses space
					game.ChoosePosition(player_1, activePlayer);
					//if winning move or tie, winner is triggered
					game.SetWinner(game.CheckforWinner(winner, player_1, player_2, tieGame));
					if (winner)
					{
						if (game.GetWinner() == 1)
							cout << player_1.name << " wins!!!\n\n";
						else if (game.GetWinner() == 2)
							cout << player_2.name << " wins!!!\n\n";
						else
							cout << "This game is a tie...\n\n";
					}
				}
				//check to see if player 2 is active
				else if (activePlayer % 2 == 0)
				{
					//display board and player chooses space
					game.ChoosePosition(player_2, activePlayer);
					//if winning move or tie, winner is triggered
					game.SetWinner(game.CheckforWinner(winner, player_1, player_2, tieGame));
					if (winner)
					{
						if (game.GetWinner() == 1)
							cout << player_1.name << " wins!!!\n\n";
						else if (game.GetWinner() == 2)
							cout << player_2.name << " wins!!!\n\n";
						else
							cout << "This game is a tie...\n\n";
					}
				}
				//displays the score if winner was triggered
				if (winner == true)
					game.DisplayScore(player_1, player_2, tieGame);
			} while (winner == false);

		}
		//say goodbye to user and exit game
		else if (choice == '3')
			cout << "Thank you for playing! Goodbye for now...\n\n";
		else
			//display invalid
			cout << "\nInvalid choice. Choose 1 or 3 if credentials have NOT been entered.\n";

	} while (choice != '3');

	return 0;
}
