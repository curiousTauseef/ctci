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

*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int matrix[2][2] =
	{
		{1, 2},
		{3, 4}
	};

	int matrix2[3][3] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	int matrix3[4][4] =
	{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	return 0;
}
