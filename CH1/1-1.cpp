/*
1.1
Is Unique: Implement an algorithm to determine if a string has all unique characters.
	   What if you cannot use additional data structures?

Hints: #44, #117, #132

44: Try a hash table
My Thoughts: Hash table would require o(n) space - not very good

117: Could a bit vector be useful?
My Thoughts: A bit set in C++ would make code less readable but improves O(1) space by a factor of 8

132: Can you solve it in O(n * log(n)) time? What might a solution like that look like?
My Thoughts: First use quicksort -> O(log(n)). Second use a modified linear search -> O(n)

*/

#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

bool bruteForce(char array[], int size);
bool optimized(char array[], int size);
bool optimized2(char array[], int size);

//True for unique, false for not unique
/*
Time Complexity: O(n^2)
Space Complexity: O(1)

- Explanation -
TC: The nested for-loops iterate through the array size^2 times on average.
SC: Temporary variables only used; no additional arrays etc. needed for this algorithm.
*/
bool bruteForce(char array[], int size)
{
	if (size <= 1) return true;

	for (int i = 0; i < size; ++i)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (array[i] == array[j])
			{
				return false;
			}
		}
	}

	return true;
}

//True for unique, false for not unique
/*
Time Complexity: O(n)
Space Complexity: O(1)

- Explanation -
TC: The loop iterates through the input "N" times
SC: Always needs constant table[256] for extended ASCII
*/
bool optimized(char array[], int size)
{
	if (size <= 1) return true;

	bool table[256];

	for (int i = 0; i < size; ++i)
	{
		int decOfAscii = array[i];
		
		if (table[decOfAscii] == true)
		{
			return false;
		}

		table[decOfAscii] = true;
	}

	return true;
}

//True for unique, false for not unique
/*
Note: This solution is an improved version of the above solution.
Time Complexity: O(n)
Space Complexity: O(1) (improved by factor of 8)

- Explanation -
TC: The loop iterates through the input "N" times
SC: Improved by a factor of 8 because a bit table uses 1 bit instead of 8 bits (previous solution)
*/
bool optimized2(char array[], int size)
{
	if (size <= 1) return true;

	bitset<256> table;

	for (int i = 0; i < size; ++i)
	{
		int decOfAscii = array[i];

		if (table[decOfAscii] == true)
		{
			return false;
		}

		table[decOfAscii] = true;	
	}

	return true;	
}


int main()
{
	//Test strings
	char nameOne[9] = "harrison";
	char nameTwo[7] = "steven";
	char nameThree[5] = "tony";
	char nameFour[4] = "?!*";

	//Brute-force solution and optimized solution
	bool checkIfUnique = bruteForce(nameTwo, 6);
	bool optimizedCIU = optimized(nameTwo, 6);
	bool optimized2CIU = optimized2(nameTwo, 6);

	cout << "Unique: " << checkIfUnique << endl;
	cout << "Unique (o): " << optimizedCIU << endl;	
	cout << "Unique (o.2): " << optimized2CIU << endl;

	return 0;
}
