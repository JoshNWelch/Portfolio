/*
Josh Welch
CST-312
Ceaser Cipher
*/

#include <iostream>
#include <string>
using namespace std;

int common_word_check(string msg[])
{
	int hits[27];
	int flag = -2;
	for (int i = 1; i <= 26; i++)
	{
		hits[i] = 0;
		for (int k = 0; k <= msg[i].length() - 2; k++)					
		{
			if (msg[i][k] == 'w' && msg[i][k + 1] == 'a' && msg[i][k + 2] == 's')			//Checks for was
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'W' && msg[i][k + 1] == 'a' && msg[i][k + 2] == 's')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'W' && msg[i][k + 1] == 'A' && msg[i][k + 2] == 'S')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 't' && msg[i][k + 1] == 'h' && msg[i][k + 2] == 'e')			//Checks for the
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'T' && msg[i][k + 1] == 'h' && msg[i][k + 2] == 'e')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'T' && msg[i][k + 1] == 'H' && msg[i][k + 2] == 'E')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'a' && msg[i][k + 1] == 'n' && msg[i][k + 2] == 'd')			//Checks for and
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'A' && msg[i][k + 1] == 'n' && msg[i][k + 2] == 'd')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'A' && msg[i][k + 1] == 'N' && msg[i][k + 2] == 'D')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'y' && msg[i][k + 1] == 'o' && msg[i][k + 2] == 'u')			//Checks for you
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'Y' && msg[i][k + 1] == 'o' && msg[i][k + 2] == 'u')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'Y' && msg[i][k + 1] == 'O' && msg[i][k + 2] == 'U')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'f' && msg[i][k + 1] == 'o' && msg[i][k + 2] == 'r')			//Checks for for
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'F' && msg[i][k + 1] == 'o' && msg[i][k + 2] == 'r')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'F' && msg[i][k + 1] == 'O' && msg[i][k + 2] == 'R')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'a' && msg[i][k + 1] == 'r' && msg[i][k + 2] == 'e')			//Checks for are
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'A' && msg[i][k + 1] == 'r' && msg[i][k + 2] == 'e')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'A' && msg[i][k + 1] == 'R' && msg[i][k + 2] == 'E')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'o' && msg[i][k + 1] == 'f' && msg[i][k + 2] == ' ')			//Checks for of
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'O' && msg[i][k + 1] == 'f' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'O' && msg[i][k + 1] == 'F' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 't' && msg[i][k + 1] == 'o' && msg[i][k + 2] == ' ')			//Checks for to
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'T' && msg[i][k + 1] == 'o' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'T' && msg[i][k + 1] == 'O' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'i' && msg[i][k + 1] == 'n' && msg[i][k + 2] == ' ')			//Checks for in
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'I' && msg[i][k + 1] == 'n' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'I' && msg[i][k + 1] == 'N' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'i' && msg[i][k + 1] == 's' && msg[i][k + 2] == ' ')			//Checks for is
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'I' && msg[i][k + 1] == 's' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'I' && msg[i][k + 1] == 'S' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'i' && msg[i][k + 1] == 't' && msg[i][k + 2] == ' ')			//Checks for it
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'I' && msg[i][k + 1] == 't' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'I' && msg[i][k + 1] == 'T' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'h' && msg[i][k + 1] == 'e' && msg[i][k + 2] == ' ')			//Checks for he
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'H' && msg[i][k + 1] == 'e' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'H' && msg[i][k + 1] == 'E' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == 'o' && msg[i][k + 1] == 'n' && msg[i][k + 2] == ' ')			//Checks for on
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'O' && msg[i][k + 1] == 'n' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == 'O' && msg[i][k + 1] == 'N' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == ' ' && msg[i][k + 1] == 'a' && msg[i][k + 2] == ' ')			//Checks for a
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == ' ' && msg[i][k + 1] == 'A' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

			if (msg[i][k] == ' ' && msg[i][k + 1] == 'i' && msg[i][k + 2] == ' ')			//Checks for i
			{
				hits[i]++;
				flag = 1;
			}
			else if (msg[i][k] == ' ' && msg[i][k + 1] == 'I' && msg[i][k + 2] == ' ')
			{
				hits[i]++;
				flag = 1;
			}

		}

	}

	if (flag == 1)
	{
		int max = 0;
		int index;
		for (int i = 1; i <= 26; i++)
		{
			if (hits[i] > max)
				index = i;
		}
		return index;
	}
	else
	{
		return flag;
	}

};

void CeaserDecryptBrute(string message)
{
	string copy, copyAr[27];

	for (int key = 1; key <= 26; key++)
	{
		copy = message;
		for (int i = 0; i < copy.length(); i++)
		{
			if (isalpha(copy[i]))
			{
				for (int ii = 0; ii < key; ii++)
				{
					if (copy[i] == 'a')
					{
						copy[i] = 'z';
					}
					else if (copy[i] == 'A')
					{
						copy[i] = 'Z';
					}
					else
					{
						copy[i]--;
					}
				}
			}

		}
		copyAr[key] = copy;
	}
	//int index = common_word_check(copyAr);                           // This commented out section eliminates the function call for the common word check and will always print all 26 possible rotations
	//if (index != -2)
	//{
	//	cout<<"Key:" << index << "   " << copyAr[index] << endl;
	//}
	//else
	//{
		for (int i = 1; i <= 26; i++)
			{
				cout<<"Key:"<<i<<"   " << copyAr[i] << endl;
			}
//	}

};
	


void main()
{
	string msg;		
	cout << "Enter message for decryption: " << endl;
	getline(cin, msg);
	CeaserDecryptBrute(msg);

}
