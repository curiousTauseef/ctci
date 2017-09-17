/*
- Palindrome Permutation - 
Given a string, write a function to check if it is a permutation of a palindrome.
A palindrome is a word or phrase that is the same forwards & backwards.
A permutation is a rearrangement of letters. The palindrome does not need to be
limited to just dictionary words. (ASCII - 128 or 256 for extended)

- Hints -

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
bool optimized(char input[]);

/*
Time Complexity: O(n) + O(n) -> O(2n) = O(n)
Goes through string with length "n" and goes through table length - 128 (constant)

Space Complexity: O(128) -> O(1) : constant extra space of size 128

Brute-force algorithm turns out to be one of the most efficient possibilities.
Gayle Laakmann's solution is difficult to read and understand quickly compared to this simple
array inplementation.

Reasons:
1. A hash table would have taken O(n) extra space
2. A bit vector/set wouldn't have the same consistency as this algorithm, nor as readable
*/
bool bruteForce(char input[])
{
	int totalLength = strlen(input);

	//Palindrome counts if it's 1 or 0 characters
	if (totalLength <= 1) return true;

	//Mistake: not initializing array to {0}, otherwise you get garbage
	int table[128] = {0}, trueLen = 0;

	//Add the frequencies to the array table
	for (int i = 0; i < totalLength; ++i)
	{
		if (isalnum(input[i]))
		{	
			++table[(int) input[i]];
			++trueLen;	
		}
	}	

	int oddCount = 0;

	//Count the number of odd frequencies
	//Bool returns 0 as false and 1 as true
	for (int p = 0; p < 127; ++p)
	{
		oddCount += table[p] % 2;
	}

	return oddCount <= 1;
}

int main()
{
	//Input string
	char input[9] = "tact coa";
	char input2[7] = "annasb";

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
