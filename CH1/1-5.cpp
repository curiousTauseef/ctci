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

using namespace std;

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

	return 0;
}
