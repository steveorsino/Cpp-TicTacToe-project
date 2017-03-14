//Stephen Orsino
//Max Walters
//Nishant Thomas
//July 7, 2016
//ttt.h

#include<string>
#include<cstdlib>
using namespace std;
//declare struct for player
struct Player
{
	//declare attributes
	string name;
	char symbol;
	int currentScore;
	//Plater constructo to initialize attributes
	Player()
	{
		name = "Empty";
		symbol = ' ';
		currentScore = 0;
	}

};

//declare TicTacToe class
class TicTacToe
{
//declare private attributes
private:
	Player player_1, player_2, tieGame;
	int currentWinner;
	char board[3][3];

public:
	//declare publice constuctors
	TicTacToe()
	{
		currentWinner = 0;
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
	TicTacToe(Player p1, Player p2, Player tg, int tempwin)
	{
		player_1 = p1;
		player_2 = p2;
		tieGame = tg;
		currentWinner = tempwin;
	}
	//Setter
	void SetWinner(int);
	//Getter
	int GetWinner();
	
	//declare function prototypes
	void ResetMatch(Player&, Player&, Player&);
	void ResetGame();
	void DisplayBoard();
	void ChoosePosition(Player, int&);
	void DisplayScore(Player, Player, Player);
	void CreatePlayer(Player&, Player&);
	int CheckforWinner(bool&, Player&, Player&, Player&);


};
