#include <iostream>
#include <random>
#include <vector>
//rock > lizard & scissors
//paper > spock & rock
//scissors > paper & lizard
//lizard > spock & paper
//spock > scissors & rock

using namespace std;

void compChoice(int randomNum);
void printOutput(string playerMove, string compMove, int playerMoveInt, int compMoveInt);
void titleCard();
int randomNumber();
void titleMenu();
void bestOfGame(int numRound);
string victoryDecider(int playerMove, int compMove);

string gameChoices[5] = { "Rock", "Paper", "Scissors", "Lizard", "Spock" };
int playerMove = 0;
int compMove = 0;
string playerMoveString;
string compMoveString;
bool playerExit = false;
bool endlessMode = false;
int playerScore = 0;
int computerScore = 0;
int curRound = 1;

int main() {

	titleCard();
	if (playerExit == false) {

		titleMenu();
		//compChoice(randomNumber());
	}

	return 0;
}
void titleCard() {
	system("CLS");
	printf("[=================================]\n");
	printf("[=================================]\n");
	printf("[ %*s%s", 11, "", "Welcome to");
	printf("%*s%s", 11, "", "]\n");
	printf("[Rock Paper Scissors Lizard Spock!]\n");
	printf("[=================================]\n");
	printf("[=================================]\n\n");
}
void titleMenu() {
	playerMove = 0;
	compMove = 0;
	playerScore = 0;
	computerScore = 0;
	curRound = 1;
	int menuSelect = 0;
	int userBestOf = 0;
	cout << "[ [1] Best of 3    ]" << endl;
	cout << "[ [2] Best of 5    ]" << endl;
	cout << "[ [3] Best of X    ]" << endl;
	cout << "[ [4] Endless Mode ]" << endl;
	cout << "[ [5] Quit         ]" << endl << endl;
	cout << "Selection: ";
	cin >> menuSelect;

	switch (menuSelect)
	{
	case 1:
		menuSelect = 0;
		bestOfGame(3);
		break;
	case 2:
		menuSelect = 0;
		bestOfGame(5);
		break;
	case 3:
		menuSelect = 0;
		cout << "Enter Number of Rounds: ";
		cin >> userBestOf;
		if (userBestOf < 2)
		{
			userBestOf = 2;
		}

		bestOfGame(userBestOf);
		break;
	case 4:
		menuSelect = 0;
		endlessMode = true;
		bestOfGame(0);
		break;
	case 5:
		playerExit = true;
		break;
	default:
		break;
	}
}
void bestOfGame(int numRound) {

	system("CLS");
	//if (endlessMode == false)
	//{
	//	if (curRound >= numRound)
	//	{
	//		playerExit = true;


	//	}
	//}
	while (curRound <= numRound && playerExit == false || endlessMode == true && playerExit == false)
	{
		cout << "[ Player Score: " << playerScore << " || " << "Computer Score: " << computerScore << " ]" << endl << endl;
		cout << "[ Round Number " << curRound << " ]" << endl << endl;
		printf("[================================================================================]\n\n");
		cout << "[ Game Selections: [1]Rock, [2]Paper, [3]Scissors, [4]Lizard, [5]Spock, [6]Quit ]" << endl << endl;
		cout << "* Enter Move: ";
		cin >> playerMove;
		cout << endl;
		//if (playerMove == 6)
		//{
		//	playerExit = true;
		//}
		switch (playerMove)
		{
		case 6:
			playerExit = true;
			/*titleCard();
			titleMenu();*/
			break;
		default:
			playerMove -= 1;
			playerMoveString = gameChoices[playerMove];
			curRound++;
			compChoice(randomNumber());
			break;
		}



	}
	if (playerScore > computerScore && playerExit == false)
	{
		cout << "[ !!!! The Player Wins !!!! ]" << endl;
		playerMove = 0;
		compMove = 0;
		playerScore = 0;
		computerScore = 0;
		curRound = 1;
		titleCard();
		titleMenu();
	}
	else if (computerScore > playerScore && playerExit == false)
	{
		cout << "[ !!!! The Computer Wins !!!! ]" << endl;
		playerMove = 0;
		compMove = 0;
		playerScore = 0;
		computerScore = 0;
		curRound = 1;
		titleCard();
		titleMenu();
	}
	else 
	{
		system("CLS");
	}

}

int randomNumber() {
	random_device random;
	mt19937 ranGen(random());
	uniform_int_distribution<int> uniq(0, 4);
	int r_int = uniq(ranGen);

	return r_int;
}
void compChoice(int randomNum) {
	compMove = randomNum;
	compMoveString = gameChoices[compMove];
	//cout << endl << compMoveString;
	printOutput(playerMoveString, compMoveString, playerMove, compMove);
}
string victoryDecider(int playerMove, int compMove) {
	string result;
	//draw
	if (playerMove == compMove)
	{
		result = "[ It is a draw ] \n\n[ !! Turn Reset !! ]\n\n";
		curRound--;
	}
	//rock
	else if (playerMove == 0 && (compMove == 3 || compMove == 2))
	{
		if (compMove == 3) {
			result = "[ Rock Crushes Lizard ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
		else if (compMove == 2)
		{
			result = "[ Rock Crushes Scissors ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
	}
	else if (playerMove == 0 && (compMove == 1 || compMove == 4))
	{
		if (compMove == 1) {
			result = "[ Paper Covers Rock ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
		else if (compMove == 4)
		{
			result = "[ Spock Vaporises Rock ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
	}
	//paper
	else if (playerMove == 1 && (compMove == 4 || compMove == 0))
	{
		if (compMove == 4) {
			result = "[ Paper Disproves Spock ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
		else if (compMove == 0)
		{
			result = "[ Paper Covers Rock ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
	}
	else if (playerMove == 1 && (compMove == 2 || compMove == 3))
	{
		if (compMove == 2) {
			result = "[ Scissors Cut Paper ] \n\n[ !!Computer Wins This Round!! ]\n\n";
			computerScore++;
		}
		else if (compMove == 3)
		{
			result = "[ Lizard Eats Paper ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
	}
	//scissors
	else if (playerMove == 2 && (compMove == 1 || compMove == 3))
	{
		if (compMove == 1) {
			result = "[ Scissors Cuts Paper ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
		else if (compMove == 3)
		{
			result = "[ Scissors Decapitate Lizard ] \n\n[ !! Player Wins This Round !! \n\n";
			playerScore++;
		}
	}
	else if (playerMove == 2 && (compMove == 0 || compMove == 4))
	{
		if (compMove == 0) {
			result = "[ Rock Crushes Scissors ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
		else if (compMove == 4)
		{
			result = "[ Spock Smashes Scissors ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
	}
	//lizard
	else if (playerMove == 3 && (compMove == 4 || compMove == 1))
	{
		if (compMove == 4) {
			result = "[ Lizard Poisons Spock ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
		else if (compMove == 1)
		{
			result = "[ Lizard Eats Paper ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
	}
	else if (playerMove == 3 && (compMove == 0 || compMove == 2))
	{
		if (compMove == 0) {
			result = "[ Rock Crushes Lizard ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
		else if (compMove == 2)
		{
			result = "[ Scissors Decapitate Lizard ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
	}
	//spock
	else if (playerMove == 4 && (compMove == 2 || compMove == 0))
	{
		if (compMove == 2) {
			result = "[ Spock Smashes Scissors ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
		else if (compMove == 0)
		{
			result = "[ Spock Vaporises Rock ] \n\n[ !! Player Wins This Round !! ]\n\n";
			playerScore++;
		}
	}
	else if (playerMove == 4 && (compMove == 1 || compMove == 3))
	{
		if (compMove == 0) {
			result = "[ Paper Disproves Spock ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
		else if (compMove == 2)
		{
			result = "[ Lizard Poisons Spock ] \n\n[ !! Computer Wins This Round !! ]\n\n";
			computerScore++;
		}
	}
	else {
		result = "[ *** !!! Input Selection Error !!! *** ]";
	}
	return result;
}
void printOutput(string playerMove, string compMove, int playerMoveInt, int compMoveInt) {
	system("CLS");
	int tempCurRound = curRound-1;
	if (tempCurRound < 1)
	{
		tempCurRound = 1;
	}
	string gameVictor = victoryDecider(playerMoveInt, compMoveInt);
	cout << "[ Player Score: " << playerScore << " || " << "Computer Score: " << computerScore << " ]" << endl << endl;
	cout << "[ Round Number " << tempCurRound << " ]" << endl << endl;
	printf("[================================================================================]\n\n\n");
	cout << "[ Player Choice: " << playerMove << " ] || [ " << "Computer Choice: " << compMove << " ]" << endl << endl;
	//cout << gameVictor << endl << endl;
	printf("[ ******************************** ]\n\n");
	printf(gameVictor.c_str());
	printf("[ ******************************** ]\n\n");
	//printf("[================================================================================]\n\n");

	system("Pause");
	system("CLS");
}