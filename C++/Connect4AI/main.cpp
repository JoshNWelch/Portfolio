#include "core.h"

///////////////////////////////////////
// TODO write the tree here:
///////////////////////////////////////
bool detect_winAI2(unsigned char gf[6][7], unsigned char playersign)
{
	//:vertical
	int count = 0;
	for (int yy = 0; yy < 7; yy++)
	{
		count = 0;
		for (int xx = 0; xx < 6; xx++)
		{
			if (gf[xx][yy] == playersign)
			{
				count++;
				if (count == 2)
					return true;
			}
			else
				count = 0;
		}
	}
	//:horizontal
	count = 0;
	for (int xx = 0; xx < 6; xx++)
	{
		count = 0;
		for (int yy = 0; yy < 7; yy++)
		{
			if (gf[xx][yy] == playersign)
			{
				count++;
				if (count == 2)
					return true;
			}
			else
				count = 0;
		}
	}

	//:diagonal
	//left top to down bottom:
	count = 0;
	for (int xx_anf = 5; xx_anf >= 3; xx_anf--)
	{
		count = 0;
		for (int ii = 0; ii < (xx_anf + 1); ii++)
		{
			if (gf[xx_anf - ii][ii] == playersign)
			{
				count++;
				if (count == 2)
					return true;
			}
			else
				count = 0;
		}
	}
	//right top to left bottom:
	count = 0;
	for (int xx_anf = 5; xx_anf >= 3; xx_anf--)
	{
		count = 0;
		for (int ii = 0; ii < (xx_anf + 1); ii++)
		{
			if (gf[xx_anf - ii][6 - ii] == playersign)
			{
				count++;
				if (count == 2)
					return true;
			}
			else
				count = 0;
		}
	}
	//left bottom to right top:
	for (int xx_anf = 0; xx_anf < 3; xx_anf++)
	{
		count = 0;
		for (int ii = 0; ii < (6 - xx_anf); ii++)
		{
			if (gf[ii][ii] == playersign)
			{
				count++;
				if (count == 2)
					return true;
			}
			else
				count = 0;
		}
	}
	//right bottom to left top:
	for (int xx_anf = 0; xx_anf < 3; xx_anf++)
	{
		count = 0;
		for (int ii = 0; ii < (6 - xx_anf); ii++)
		{
			if (gf[ii][6 - ii] == playersign)
			{
				count++;
				if (count == 2)
					return true;
			}
			else
				count = 0;
		}
	}
	return false;
}
bool detect_winAI3(unsigned char gf[6][7], unsigned char playersign)
{
	//:vertical
	int count = 0;
	for (int yy = 0; yy < 7; yy++)
	{
		count = 0;
		for (int xx = 0; xx < 6; xx++)
		{
			if (gf[xx][yy] == playersign)
			{
				count++;
				if (count == 3)
					return true;
			}
			else
				count = 0;
		}
	}
	//:horizontal
	count = 0;
	for (int xx = 0; xx < 6; xx++)
	{
		count = 0;
		for (int yy = 0; yy < 7; yy++)
		{
			if (gf[xx][yy] == playersign)
			{
				count++;
				if (count == 3)
					return true;
			}
			else
				count = 0;
		}
	}

	//:diagonal
	//left top to down bottom:
	count = 0;
	for (int xx_anf = 5; xx_anf >= 3; xx_anf--)
	{
		count = 0;
		for (int ii = 0; ii < (xx_anf + 1); ii++)
		{
			if (gf[xx_anf - ii][ii] == playersign)
			{
				count++;
				if (count == 3)
					return true;
			}
			else
				count = 0;
		}
	}
	//right top to left bottom:
	count = 0;
	for (int xx_anf = 5; xx_anf >= 3; xx_anf--)
	{
		count = 0;
		for (int ii = 0; ii < (xx_anf + 1); ii++)
		{
			if (gf[xx_anf - ii][6 - ii] == playersign)
			{
				count++;
				if (count == 3)
					return true;
			}
			else
				count = 0;
		}
	}
	//left bottom to right top:
	for (int xx_anf = 0; xx_anf < 3; xx_anf++)
	{
		count = 0;
		for (int ii = 0; ii < (6 - xx_anf); ii++)
		{
			if (gf[ii][ii] == playersign)
			{
				count++;
				if (count == 3)
					return true;
			}
			else
				count = 0;
		}
	}
	//right bottom to left top:
	for (int xx_anf = 0; xx_anf < 3; xx_anf++)
	{
		count = 0;
		for (int ii = 0; ii < (6 - xx_anf); ii++)
		{
			if (gf[ii][6 - ii] == playersign)
			{
				count++;
				if (count == 3)
					return true;
			}
			else
				count = 0;
		}
	}
	return false;
}
class gamefieldstate
	{
	public:
		unsigned char gf[6][7];	//should have a copy of the current situation
		int evaluate;			//kinda 1 .. win -1...loose, 0 ..unknown, or whatever...
		gamefieldstate *parent; //pointer to last move
		gamefieldstate *next[7]; //pointer to the next 7 possibilities, for each row! let it NULL if the row is full
		gamefieldstate()
			{
			parent = NULL;
			for (int ii = 0; ii < 7; ii++)
				next[ii] = NULL;
			}
		~gamefieldstate()
		{
			for (int i = 0; i <= 6; i++)
			{
				if (next[i])
					delete next[i];
			}
		}
		//suggestion:
		void make_new_moves(unsigned char cgf[6][7], int lvl, int op[7], int &or)
		{

			if (lvl == 7)
			{
			return;
			}
			

			char v;
			int n;
			if (lvl % 2==0)
			{
				v = 'O';
				n = 0;
			}
			else
			{
				v = 'X';
				n = 1;
			}

			gamefieldstate *p = new gamefieldstate;
			int row;
			for (int i = 0; i < 7; i++)
			{
				p->next[i] = new gamefieldstate();
				for (int xx = 0; xx < 6; xx++)
				for (int yy = 0; yy < 7; yy++)
					p->next[i]->gf[xx][yy] = cgf[xx][yy];
			}

		

			for (int ii = 0; ii < 7; ii++)
			{
				//p->parent;
				
			for (row = 5; row >= 0; row--)
			{
				if (p->next[ii]->gf[row][ii] == 250)
				{
					p->next[ii]->gf[row][ii] = v; break;
				}
			}
			}

		if (n == 0)
		{
				for (int i = 0; i < 7; i++)
				{
					if (detect_winAI2(p->next[i]->gf, v) == true)
					{
						op[i] += 1;
					}
				}
				for (int i = 0; i < 7; i++)
				{
					if (detect_winAI3(p->next[i]->gf, v) == true)
					{
						op[i] += 3;
					}
				}
				for (int i = 0; i < 7; i++)
				{
					if (detect_win(p->next[i]->gf, v) == true)
					{
						if (lvl == 0)
						{
							op[i] = 100;
							return;
						}
						else
						{
							op[i] += 30;
						}
					}
				}
				for (int i = 0; i < 7; i++)
				{
					for (row = 5; row >= 0; row--)
					{
						if (p->next[i]->gf[row][i] == 250)
						{
							break;
						}
						else if (row < 0)
						{
							op[i] = -100;
						}
					}
				}
		}
		else
		{
			for (int i = 0; i < 7; i++)
			{
				if (detect_winAI2(p->next[i]->gf, v) == true)
				{
					op[i] -= 1;
				}
			}
			for (int i = 0; i < 7; i++)
			{
				if (detect_winAI3(p->next[i]->gf, v) == true)
				{
					op[i] -= 5;
				}
			}
			for (int i = 0; i < 7; i++)
			{
				if (detect_win(p->next[i]->gf, v) == true)
				{
					if (lvl == 1)
					{
						//op[i] =10000;
						or = i;
					}
					else
					{
						op[i] -= 150;
					}
				}
			}
			for (int i = 0; i < 7; i++)
			{
				for (row = 5; row >= 0; row--)
				{
					if (p->next[i]->gf[row][i] == 250)
					{
						break;
					}
					else if (row < 0)
					{
						op[i] = -100;
					}
				}
			}
		}
			lvl++;
			for (int i = 0; i < 7; i++)
			{
				make_new_moves(p->next[i]->gf, lvl,op,or);
			}
			delete p;
			return;

		}//makes all 7 new moves and detects weither or not this is a good idea. 
		void delete_tree()
		{
			for (int i = 0; i <= 6; i++)
			{
				if (next[i])
					next[i]->delete_tree();
			}
			delete this;
		}
	};
//**************************************
// AI moves here
//**************************************
bool artificial_intelligence(unsigned char gf[6][7])
	{
	gamefieldstate b;// = new gamefieldstate;
	int over_ride = -1;
	int level = 0;
	int score = 0;
	int best = 3;
	int option[7];
	for (int i = 0; i < 7; i++)
	{
		option[i] = 0;
	}

	//use detect_win(gamefield, 'O') for detection if the AI wins and 'X' if tt eplayer wins
	
	b.make_new_moves(gf,level,option,over_ride);
	
	if (over_ride == -1)
	{
		for (int i = 0; i < 7; i++)
		{
			if (option[i] > score)
			{
				score = option[i];
				best = i;
			}
		}
	}
	else
	{
		best = over_ride;
	}
		int colums_throw = best;
	//cout << "select column: ";
	//cin >> colums_throw;
	if (colums_throw < 0 || colums_throw >= 7)
		return false;//wrong entry, call function again


	//check how far it goes from bottom to top: 
	int row;
	for (row = 5; row >= 0; row--)
		{
		if (gf[row][colums_throw] == 250)
			{
			gf[row][colums_throw] = 'O'; break;
			}
		}
	if (row < 0)
		{
		cout << "row is full, choose again" << endl;
		return false;//wrong entry, call function again
		}
	return true;
	}



void main()
	{
	unsigned char gamefield[6][7];//6 rows, 7 columns

	for (int xx = 0; xx < 6; xx++)
		for (int yy = 0; yy < 7; yy++)
			gamefield[xx][yy] = 250;


print_gamefield(gamefield);
	while (1)
		{
		

		//read
		int colums_throw = -1;
		cout << "select column (0..6): ";
		cin >> colums_throw;
		if (colums_throw < 0 || colums_throw >= 7)break;//end program

		//check how far it goes from bottom to top:
		int row = 5;
		for (row = 5; row >= 0; row--)
			{
			if (gamefield[row][colums_throw] == 250)
				{
				gamefield[row][colums_throw] = 'X'; break;
				}
			}
		if (row < 0)
			{
			cout << "row is full, choose again" << endl;
			continue;
			}
		print_gamefield(gamefield);
		if(detect_win(gamefield, 'X')==true)
			{
			print_gamefield(gamefield);
			cout << "you have won!" << endl;
			break;
			}

		//AI:
		while (!artificial_intelligence(gamefield));
		print_gamefield(gamefield);
		if (detect_win(gamefield, 'O') == true)
			{
			print_gamefield(gamefield);
			cout << "you have lost!" << endl;
			break;
			}
		}
	}