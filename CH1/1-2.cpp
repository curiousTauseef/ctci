/*
- Check Permutation-
Given 2 strings, write a method to decide if one is a permutation of the other.

- Hints -

#1: Describe what it means for two strings to be permutations of each other. Now look at the
definition you provided. Can you check the strings against that definition?

#84: There is one solution that is O(n * log(n)) time. Another solution uses some space, but is O(n) time.
Mergesort will have the TC of O(n * log(n)) time. It takes up O(n) SC.

#122: Could a hash table be useful?
Yes, if the two strings map to the same index, then we have a hit.
The time complexity is O(1), and the space complexity is O(n).

#131: Two strings that are permutations should have the same characters, but in different orders. Can you
make the orders the same?
By using mergesort, you can make the orders the same then check both strings letter by letter.

*/

#include <iostream>
#include <cstring>

using namespace std;

bool bruteForce(char array1[], char array2[], int size);
bool optimized1(int array1[], int array2[], int size);

/*
TC: O(n^2)
SC: O(1)
*/

bool bruteForce(char array1[], char array2[], int size)
{
	bool found;

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (array1[i] == array2[j])
			{
				found = true;
			}

			if (j == (size - 1) && !found)
			{
				return false;
			}
		}
	}	

	return true;
}

/*
TC: O(2n) = O(n)
SC: O(1) *always requires table[128]*
*/

bool optimized1(char array1[], char array2[], int size)
{
	int table[128];

	//Increment an index corresponding to 'char'
	for (int i = 0; i < size; ++i)
	{
		int index = array1[i];
		table[index] += 1;
	}

	//Decrement an index corresponding to 'char'
	for (int j = 0; j < size; ++j)
	{
		int index = array2[j];
		table[index] -= 1;

		//For every increment, there must be decrement if arr1.length == arr2.length
		if (table[index] < 0)
		{
			return false;
		}
	}
	
	return true;	
}

int main()
{
	//Test strings
	char array1[4] = "cat";
	char array2[4] = "tac";

	int size = strlen(array1);

	bool checkIfPermutation = bruteForce(array1, array2, size);
	bool optimizedCheck1 = optimized1(array1, array2, size);

	cout << "Permutation: " << checkIfPermutation << endl;
	cout << "Permutation (o1): " << optimizedCheck1 << endl;

	return 0;
}
