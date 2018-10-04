/*
Joshua Welch
CST 311
Programing Assignment 3
*/
#include <iostream>
using namespace std;
#define size 7							//Set to 7 for example given, but easily change to allow for more or less nodes


class djikstra
{
public:
	int network[size][size];
	int table[size][size];
	char nodes[size][size];
	char prevnodescol[size];
	char prevnodesrow[size];
	int row[size];

djikstra()
{
	for (int i = 0; i < size; i++)
	{
		for (int ii = 0; ii < size; ii++)
		{
			network[i][ii] = 0;
			table[i][ii] = 0;
			nodes[i][ii] = 0;
		}
		prevnodescol[i] = 0;
		prevnodesrow[i] = 0;
		row[i] = 0;
	}
}

void copy_network(int a[size][size])				//Allows for copying a new 2d array into the network 2d array
{
	for (int i = 0; i < size; i++)
	{
		for (int ii = 0; ii < size; ii++)
		{
			network[i][ii] = a[i][ii];
		
		}
	
	}
}

void create_table(char node)
{
	int start_node = node_to_index(node);
	int min,mindex;
	int node_cost = 0;
	prevnodescol[0] = node;								//Char values for N'
	for (int ii = 0; ii < size; ii++)					//Sets first row of table
	{
		table[0][ii] = network[start_node][ii];
	}
	for (int ii = 0; ii < size; ii++)					//Zeros out column of chosen node
	{
		network[ii][start_node]=0;
	}


	for (int i = 0; i < size-1; i++)						//Row loop
	{
		for (int ii = 0; ii < size; ii++)
		{
			if (table[i][ii] != 0)						//Sets min to first non-zero cost
			{
				mindex = ii;
				min = table[i][ii];
				node_cost = min;
				break;
			}
		}
		for (int ii = 0; ii < size; ii++)
		{
			if (table[i][ii] != 0 && table[i][ii]<min)		//Checks if cost at ii<min and sets min
			{
				mindex = ii;
				min = table[i][ii];
				node_cost = min;
			}
		}

		for (int ii = 0; ii < size; ii++)
		{
			if (table[i][ii] != 0 && network[mindex][ii] != 0 && table[i][ii] > network[mindex][ii] + node_cost)	//Fills next row of table with the lesser of the 2 row's value
			{
				table[i+1][ii] = network[mindex][ii] + node_cost;
			}
			else if (network[mindex][ii] != 0 && table[i][ii]==0)
			{
				table[i + 1][ii] = network[mindex][ii] + node_cost;
			}
			else
			{
				table[i+1][ii] = table[i][ii];
			}
		}
		table[i + 1][mindex] = 0;							//Zeros out column of chosen node

		for (int ii = 0; ii < size; ii++)					//Zeros out column of chosen node
		{
			network[ii][mindex] = 0;
		}
		
		prevnodescol[i+1] = index_to_node(mindex);			//Sets N' values
	}
}

void print_table()											//Prints a well formatted table with all values including which nodes are selected.
{
	cout << "Step      N'            D(t)     D(u)     D(v)     D(w)     D(x)     D(y)     D(z)" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "  " << i<<"     ";
		for (int ii = 0; ii <= i; ii++)
		{
			cout << prevnodescol[ii];
			if (ii != i)
				cout << ",";
		}
		for (int ii = i; ii <= size; ii++)
		{
			cout << "  ";
		}
		for (int ii = 0; ii < size; ii++)
		{
			cout << table[i][ii] << "        ";
		}
		cout << endl;
	}

}

int node_to_index(char node)						//Turns node character into an index number
{
	int index=0;
	if (node == 't')
		index = 0;
	else if (node == 'u')
		index = 1;
	else if (node == 'v')
		index = 2;
	else if (node == 'w')
		index = 3;
	else if (node == 'x')
		index = 4;
	else if (node == 'y')
		index = 5;
	else if (node == 'z')
		index = 6;

	return index;
}

char index_to_node(int node)					//Turns index number into a character value for node
{
	char index;
	if (node == 0)
		index = 't';
	else if (node == 1)
		index = 'u';
	else if (node == 2)
		index = 'v';
	else if (node == 3)
		index = 'w';
	else if (node == 4)
		index = 'x';
	else if (node == 5)
		index = 'y';
	else if (node == 6)
		index = 'z';

	return index;
}

};




void main()
{
	djikstra net1;
	char c;
	int networknodes[size][size]=						//Set values to example, but new array could be created with any value
	{
		{ 0, 2, 4, 0, 0, 7, 0 },
		{ 2, 0, 3, 3, 0, 0, 0 },
		{ 4, 3, 0, 4, 3, 8, 0 },
		{ 0, 3, 4, 0, 6, 0, 0 },
		{ 0, 0, 3, 6, 0, 6, 8 },
		{ 7, 0, 8, 0, 6, 0, 12 },
		{ 0, 0, 0, 0, 8, 12, 0 }
	};
	net1.copy_network(networknodes);					//Copies array into our network class array
	cout << "Which node would you like to start calculation from?(enter lowercase letter t,u,v,w,x,y, or z as a selection)" << endl;
	cin >> c;
	net1.create_table(c);								//Creates our table using Djikstra's cost calculation
	net1.print_table();									//Prints table

}