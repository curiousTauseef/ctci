/*
- One Away - 
There are three types of edits that can be performed on strings:
1. Insert a character
2. Remove a character
3. Replace a character

Given 2 strings, write a function to check if they are one edit or zero edits away.

- Hints -

#23: Start with the easy thing. Can you check each of the conditions separately?

#97: What is the relationship between the "insert character" option and the "remove character"
option? Do these need to be 2 separate checks?

#130: Can you do all 3 checks in a single pass?

*/

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

bool bruteForce(char str1[], char str2[]);

/*
Time Complexity: O(n)
Goes through 2 arrays, not 1 twice

Space Complexity: O(1) 
Doesn't use any extra memory space
*/
bool bruteForce(char str1[], char str2[])
{
	int strDiff = strlen(str1) - strlen(str2);

	//Can't exceed difference of 1 character
	if (abs(strDiff) > 1) return false;

	int diffCount = 0;
	bool flag = false;

	//Find a match in the other array going 1 by 1 in the first array
	for (int i = 0; i < strlen(str1); ++i)
	{
		for (int j = 0; j < strlen(str2); ++j)
		{
			if (str1[i] == str2[j])
			{
				//Found a match
				flag = true;
			}
		}

		//Increment char difference count
		if (!flag)
		{
			 ++diffCount;
		}

		if (diffCount > 1) return false;

		//Reset found flag
		flag = false;
	}

	return true;
}

int main()
{
	//-> true
	char str1[5] = "pale";
	char str2[4] = "ple";

	//-> true	
	char str3[6] = "pales";
	char str4[5] = "pale";

	//-> false
	char str5[5] = "pale";
	char str6[5] = "bake";

	bool checkEdit = bruteForce(str1, str2);
	bool checkEdit2 = bruteForce(str3, str4);
	bool checkEdit3 = bruteForce(str5, str6);

	cout << "T1) Differ by 0 or 1 edits (T/F): " << checkEdit << endl;
	cout << "T2) Differ by 0 or 1 edits (T/F): " << checkEdit2 << endl;
	cout << "T3) Differ by 0 or 1 edits (T/F): " << checkEdit3 << endl;

	return 0;
}
