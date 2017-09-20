/*
- Rotate Matrix -
Given an image represented by an NxN matrix, where each pixel
in the image is 4 bytes, write a method to rotate the image
by 90 degrees. Do this IN-PLACE.

- Hints -

#51: Try thinking about it layer by layer. Can you rotate
a specific layer?

#100: Rotating a specific layer would just mean swapping
the values in four arrays. 

If you were asked to swap the values in two arrays, 
could you do this? Can you then extend it to four arrays?

Link: 
https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function

Found this link useful for remembering how to pass 2D arrays in C++
*/

#include <iostream>
#include <cstring>

using namespace std;

/*
Used template + pass by reference to prevent any loss of dimension info
Safest approach towards passing 2-D arrays in C++
*/
template <size_t N>
void rotateMatrix(int (&matrix)[N][N]);

template <size_t N>
void printMatrix(int (&matrix)[N][N]);

/*
Time Complexity: O(N^2)
Two loops to transpose the matrix: O(N^2)
One loop to reverse leftmost & rightmost columns inward O(N)
O(N^2) + O(N) ~= O(N^2)

Space Complexity: O(1)
Does not use any auxiliary array etc.
*/
template <size_t N>
void rotateMatrix(int (&matrix)[N][N])
{
	//Boundary case 
	if (N < 1) return;

	int row, col;

	//Transpose the matrix
	//Rows becomes columns, diagonal does not change
	for (int i = 0; i < N; ++i)
	{
		row = i + 1;
		col = i + 1;

		while (row < N && col < N)
		{
			swap(matrix[row][i], matrix[i][col]);
			++row;
			++col;
		}	
	}

	int left = 0, right = N - 1;

	//Swap each column (leftmost ---- rightmost)
	//Keep moving left & right columns to the middle
	for (int j = 0; j < N / 2; ++j)
	{
		int rTemp = right;

		//Use a temporary right value to not
		//lose track of column swapping
		while (left < N && rTemp < N)
		{
			swap(matrix[left][j], matrix[left][rTemp]);
			++left;
		}

		left = j;
		right -= 1;
	}

}

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

	int N2 = sizeof(matrix2[0])/sizeof(matrix[0][0]);

	int matrix3[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	int N3 = sizeof(matrix3[0])/sizeof(matrix[0][0]);

	//Testing the matrices with the 90 degree rotation
	rotateMatrix(matrix);
	printMatrix(matrix);

	cout << endl;

	rotateMatrix(matrix2);
	printMatrix(matrix2);

	cout << endl;

	rotateMatrix(matrix3);
	printMatrix(matrix3);

	return 0;
}
