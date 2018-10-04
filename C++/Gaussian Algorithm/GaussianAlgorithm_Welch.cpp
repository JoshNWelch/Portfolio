/*
Joshua Welch
Gausssian Algorithm
Math 270
*/

#include <iostream>
using namespace std;

void ero(float mat[100][100],int numcol,int numrow)		// Elementary Row Operations
{
	float factor;
	int rt, ct;
	rt = ct = 0;
	for (int n = 0; n < numcol&& n < numrow; n++)
	{
		int flag = 0;
		rt=ct = n;
		if (mat[n][n] != 0)							//Makes sure pivot doesn't =0
		{
			factor = mat[n][n];
			mat[n][n] = mat[n][n] / factor;			//Sets Pivot to 1
		}
		else                                        //If Pivot =0 skips the column and row.
		{
			flag = 1;
		}

		if (flag == 0)
		{
			for (int i = 0; i < numcol; i++)
			{
				if (i == ct)						//Column Tracker to skip over Pivot
				{
					i++;
				}
				mat[n][i] = mat[n][i] / factor;		//Divides row by factor
			}
		
			for (int ii = 0; ii < numrow; ii++)
			{
				if (ii == rt)						//Row Tracker to skip over row we are setting to 1
				{
					ii++;
				}
				if (mat[ii][n] != 0)				//Checks to make sure value isnt zero before setting fac
				{
					factor = mat[ii][n];			//Sets factor for column/row
					mat[ii][n] = mat[ii][n] - factor;	//Sets column to zero
				}
				else                                //If value is zero breaks out of loop to skip row
				{
					break;
				}

				for (int x = 0; x < numcol; x++)
				{
					if (x == ct)						//Column Tracker to skip over zeroed column
					{
						x++;
					}
					mat[ii][x] = mat[ii][x] - (mat[n][x] * factor);		//Multiplys by factor and subtracts whole row
				}
			}
		}
	}
}

void swap(float mat[100][100],int pivot, int numcol)		//Swaps first row with pivot
{
	float temp[100][100];
	for (int i = 0; i < numcol; i++)
	{
		temp[0][i] = mat[0][i];
		mat[0][i] = mat[pivot][i];
		mat[pivot][i] = temp[0][i];
	}
}

void print_matrix(float mat[100][100], int numcol, int numrow)		//Prints Matrix
{
	for (int i = 0; i < numrow; i++)
	{
		cout << "       ";
		for (int ii = 0; ii < numcol; ii++)
		{
			if (ii == numcol - 1)
			{
				cout << "| " << mat[i][ii];
			}
			else
			{
				cout << mat[i][ii] << "  ";
			}
		}
		cout << endl;
	}
}

void main()
{
	int col, row;
	float matrix[100][100];
	int pivot,flag;
	pivot = flag = 0;
	cout << "Enter number of equations: " << endl;			//Sets number of Rows
	cin >> row;									
	cout << "Enter number of variables: " << endl;			//Sets number of columns
	cin >> col;
	col++;													//Adds column for answer to equation
	
	for (int i = 0; i < row; i++)							//Loop to fill in matrices
	{
		for (int ii = 0; ii < col; ii++)
		{
			if (ii == col - 1)
			{
				cout << "Enter solution for row: " << i+1 << endl;
				cin >> matrix[i][ii];
			}
			else
			{
				cout << "Enter variable for row:" << i+1 << " column:" << ii+1 << endl;
				cin >> matrix[i][ii];
			}
		}
	}

	cout << "Before ERO: " << endl;
	print_matrix(matrix, col, row);							//Prints unmodified matrix
	cout << endl;

	if (matrix[0][0] == 1)									//Checks first variable before running ero
	{
		ero(matrix,col,row);
		flag = 1;
	}
	else                                                    //Searches to see if any values in the first column are equal to 1 then swaps
	{
		for (int i = 0; i < row; i++)
		{
			if (matrix[i][0] == 1)
			{
				pivot = i;
				swap(matrix, pivot,col);
				ero(matrix,col,row);
				flag = 1;
				break;
			}
		}
	}
	if (flag==0)											//Searches to find any non-zero value to swap with
	{
		for (int i = 0; i < row; i++)
		{
			if (matrix[i][0] != 0)
			{
				pivot = i;
				swap(matrix, pivot,col);
				ero(matrix,col,row);
				break;
			}
		}
	}

	cout<<"After ERO: " << endl;
	print_matrix(matrix, col, row);							//Prints new Matrix
	
	




}