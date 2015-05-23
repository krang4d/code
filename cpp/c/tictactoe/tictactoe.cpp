#include <iostream>
using namespace std;

int print_board(char* board[])
{
	cout <<  board[6] << "|" << board[7] <<"|"<< board[8] << endl;
	cout <<  board[3] << "|" << board[4] <<"|"<< board[5] << endl;
	cout <<  board[0] << "|" << board[1] <<"|"<< board[2] << endl;
/*
	cout << "Ganme board:" << endl;
	cout << "-"board[6]"-"|"-"board[7]"-"|"-"board[8]"-"<< endl;
	cout << "-"board[3]"-"|"-"board[4]"-"|"-"board[5]"-"<< endl;
	cout << "-"board[0]"-"|"-"board[1]"-"|"-"board[2]"-"<< endl;
	cout << "\nYour move: "<< endl;
*/

	return 0;
	
}

bool has_wonQ(char player)
{
	int wins[][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {0,3,6}, {1,4,7}, {2,5,8 }, {0,4,8}, {2,4,6}};
	
	for(int i = 0; i<8 ; i++)
	{
		int count = 0;
		for(int j = 0; j<3; j++)
		{
			{
				if(board[wins[i][j]] == player)
					count++;	
			}
		if(count == 3)
			return true;
		}
	}
	return false;
}

int main()
{
	int move;
	char* board[] = {"---","---","---","---","---","---","---","---","---"};
	
	cout << "Move options:" << endl;
	cout << "-7-|-8-|-9-" << endl;
	cout << "-4-|-5-|-6-" << endl;
	cout << "-1-|-2-|-3-" << endl;
	cout << endl;

	for ( int i = 0; i<9; i++)
	{
		cout << "Please enter a legal move (1-9): \n";
		cin >> move;
		if (move>9 || move<1)
		{
			cout << "Please enter a legal move (1-9): \n";
			cin >> move;
		} 
		board[move-1] = "-o-";
		print_board(board);
	}
	return 0;
}
