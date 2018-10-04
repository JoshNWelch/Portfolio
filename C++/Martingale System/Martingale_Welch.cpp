/*
Joshua Welch
Math 270
Programing Assignment Week 2
*/
#include <iostream>
#include <time.h>
using namespace std;






void main()
{
	srand(time(NULL));
	int win, lose, game, money;
	win = lose = game = money = 0;
	int wheel = 0;
	int bet = 1;

		while (game < 100)
		{
			wheel = rand() % 2;			//Red = 0, Black = 1;
			if (wheel == 0)
			{
				money += bet;
				bet = 1;
			}
			else
			{
				money -= bet;
				bet *= 2;
			}
			
			if (money >= 5)
			{
				win++;
				game++;
				money = 0;
				bet = 1;
			}
			else if (money < -100)
			{
				lose++;
				game++;
				money = 0;
				bet = 1;
			}

		}

	cout << "Number of wins: " << win << endl;
	cout << "Number of loses: " << lose << endl;
}