/*
- Zero Matrix -
Write an algorithm such that if an element in an MxM matrix is 0,
its entire row and column are set to 0. Do this in-place.

- Hints -

#17: If you just cleared the rows and columns as you found 0s,
you'd likely wind up clearing the whole matrix. Try finding the
cells with zeros first before making any changes to the matrix.

#74: Can you use O(n) additional space instead of O(n^2)? What
information do you really need from the list of cells that are
zero?

You can use O(1) space.

#102: You probably need some data storage to maintain a list of
the rows and columns that need to be zeroed. Can you reduce the
additional space usage to O(1) by using the matrix itself for
data storage?

*/

#include <iostream>

using namespace std;

//With templates, we can pass in these static arrays by reference.

template <size_t M>
void printMatrix(int (&matrix)[M][M]);

template <size_t M>
void zeroMatrix(int (&matrix)[M][M]);

template <size_t M>
void nullifyRow(int (&matrix)[M][M], int index);

template <size_t M>
void nullifyCol(int (&matrix)[M][M], int index);


template <size_t M>
void printMatrix(int (&matrix)[M][M])
{
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << matrix[i][j] << "  ";
		}	

		cout << endl;
	}
}

/*
Time Complexity: O(N^2)
Most of the time used up is in the nested for-loop, thus O(N).

Space Complexity: O(1)
We use row #0 and col #0 as auxiliary arrays to do the algorithm.

Algorithm:
1. Search for 0s in row #0
	-create a boolean to determine whether row #0 has 0s
2. Search for 0s in col #0
	-create a boolean to determine whether col #0 has 0s
3. Search for 0s in the REST of the matrix
	-set the leftmost/topmost columns to 0 corresponding to the 0s found
4. Search for 0s in row #0
	-clear the respective rows
5. Search for 0s in col #0
	-clear the respective columns
6. Clear row #0 and/or col #0 based upon the two booleans
*/
template <size_t M>
void zeroMatrix(int (&matrix)[M][M])
{
	//Boundary case
	if (M < 2) return;

	bool rowHasZero;
	bool colHasZero;

	//Look for zeros in row #0
	for (int i = 0; i < M; ++i)
	{
		if (matrix[0][i] == 0)
		{
			rowHasZero = true;
			break;	
		}
	}

	//Look for zeros in col #0
	for (int j = 0; j < M; ++j)
	{
		if (matrix[j][0] == 0)
		{
			colHasZero = true;
			break;	
		}
	}

	//Find zeros from row #0 to row #M - 1
	//Set the leftmost row values to 0 if found in current row
	for (int k = 1; k < M; ++k)
	{
		//Find zeros from col #0 to col #M - 1
		//Set the topmost col values to 0 if found in current col
		for (int l = 1; l < M; ++l)
		{
			if (matrix[k][l] == 0)
			{
				matrix[k][0] = 0;
				matrix[0][l] = 0;	
			}	
		}
	}

	//Clear rows with 0s marked on leftmost columns
	for (int r = 1; r < M; ++r)
	{
		if (matrix[r][0] == 0)
		{
			nullifyRow(matrix, r);
		}
	}		

	//Clear columns with 0s marked on topmost columns
	for (int c = 1; c < M; ++c)
	{
		if (matrix[0][c] == 0)
		{
			nullifyCol(matrix, c);
		}
	}

	//Set row #0 to all zeros if zeros were found in beginning
	if (rowHasZero)
	{
		nullifyRow(matrix, 0);
	}

	//Set col #0 to all zeros if zeros were found in beginning
	if (colHasZero)
	{
		nullifyCol(matrix, 0);
	}
}

//Clears a row with 0s
template <size_t M>
void nullifyRow(int (&matrix)[M][M], int index)
{
	for (int counter = 0; counter < M; ++counter)
	{
		matrix[index][counter] = 0;
	}
}

//Clears a col with 0s
template <size_t M>
void nullifyCol(int (&matrix)[M][M], int index)
{
	for (int counter = 0; counter < M; ++counter)
	{
		matrix[counter][index] = 0;
	}
}

int main()
{
	int matrix[2][2] =
	{
		{1, 2},
		{3, 0}
	};

	int matrix2[3][3] =
	{
		{1, 0, 3},
		{0, 5, 6},
		{7, 8, 9}
	};

	int matrix3[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 0, 8},
		{9, 0, 11, 12},
		{13, 14, 15, 16}
	};

	zeroMatrix(matrix);
	printMatrix(matrix);

	cout << endl;

	zeroMatrix(matrix2);
	printMatrix(matrix2);

	cout << endl;

	zeroMatrix(matrix3);
	printMatrix(matrix3);

	return 0;
}
