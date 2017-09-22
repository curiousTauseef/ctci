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

#102: You probably need some data storage to maintain a list of
the rows and columns that need to be zeroed. Can you reduce the
additional space usage to O(1) by using the matrix itself for
data storage?

*/

#include <iostream>

using namespace std;

template <size_t N>
void printMatrix(int (&matrix)[N][N]);

template <size_t N>
void printMatrix(int (&matrix)[N][N])
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << matrix[i][j] << "  ";
		}	

		cout << endl;
	}
}

int main()
{
	int matrix[2][2] =
	{
		{1, 2},
		{3, 4}
	};

	int N = sizeof(matrix[0])/sizeof(matrix[0][0]);

	int matrix2[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int N2 = sizeof(matrix2[0])/sizeof(matrix2[0][0]);

	int matrix3[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12}
	};

	int N3 = sizeof(matrix3[0])/sizeof(matrix3[0][0]);

	return 0;
}
