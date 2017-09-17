/*
- Palindrome Permutation - 
Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards & backwards.
A permutation is a rearrangement of letters. The palindrome does not need to be
limited to just dictionary words. (ASCII - 128 or 256 for extended)

Hints:

#106: No need to generate permutations - too inefficient
Use hint #121 for a possible solution

#121: What characteristics would a string that is a permutation
of a palindrome have?
Even string -> all characters % 2 == 0
Odd string -> all but 1 character % 2 == 0

#134: Have you tried a hash table? You should get this to O(n) TC
TC: O(n) and SC: (n)

#136: Can you reduce the space usage by using a bit set?
Not quite
*/

#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

bool bruteForce(char input[]);

bool bruteForce(char input[])
{
	int totalLength = strlen(input);

	if (totalLength <= 1)
	{
		return true;
	}

	//Mistake: not initializing array to {0}, otherwise you get garbage
	int table[128] = {0}, trueLen = 0;

	for (int i = 0; i < totalLength; ++i)
	{
		if (isalnum(input[i]))
		{	
			int index = input[i];
			table[index] += 1;
			++trueLen;	
		}
	}	

	int oddCount = 0;

	for (int p = 0; p < 127; ++p)
	{
		if (trueLen % 2 == 0)
		{
			if (table[p] % 2 != 0)
			{
				return false;
			}
		}
		else
		{
			if (table[p] % 2 != 0)
			{
				++oddCount;
			}

			if (oddCount > 1) return false;
		}
	}
/*
	if (trueLen % 2 == 0)
	{
		for (int j = 0; j < 127; ++j)
		{
			if (table[j] % 2 != 0)
			{
				return false;
			}
		}
	}
	else
	{
		for (int k = 0; k < 127; ++k)
		{
			if (table[k] % 2 != 0)
			{
				++oddCount;
			}
			
			if (oddCount > 1)
			{
				return false;
			}
		}
	}
*/
	return true;
}

int main()
{
	//Input string
	char input[9] = "tact coa";
	char input2[7] = "annasp";

	//Boundary-case
	char test1[1] = "";

	bool checkIfPOP = bruteForce(input2);

	cout << "Permutation of String: " << checkIfPOP << endl;	

	/*
	Expected output
	True 
	(permutation: "taco cat", "atco cta", etc.)
	*/

	return 0;
}
