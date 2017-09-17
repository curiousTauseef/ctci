/*
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. Try to do this algorithm in-place.

EXAMPLE
Input:  "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"

HINTS
#53: It's often easiest to modify strings by going from the end of the string to the beginning
*
Filling in the contents of the "real string" starting at the extra space to the front is the
most efficient algorithm.

#118: You might find out that you need to know the number of spaces. Can you just count them?
*
Yes, you can count the number of spaces starting from the end.
*/

#include <iostream>
#include <cstring>

using namespace std;

void bruteForce(char input[], char result[]);
void optimized(char input[], int sizeString);

/*
Time Complexity: O(n) -> goes through entire input array
Space Complexity: O(n) -> requires an auxiliary array
*/
void bruteForce(char input[], char result[])
{
	int spaces = 0;
	int countFromEnd = strlen(input);
	int newArrCounter = 0;
	int totalSize = strlen(input);

	//Count the spaces to get the "real string"
	while (input[countFromEnd] == ' ')
	{
		++spaces;
		--countFromEnd;
	}

	//Copy from beginning to end, but insert "%20" for every ' ' encountered
	for (int i = 0; i < totalSize + 1 && newArrCounter < totalSize - spaces; ++i)
	{
		result[newArrCounter] = input[i];
			
		if (input[i] == ' ')
		{
			result[newArrCounter] = '%';
			result[newArrCounter + 1] = '2';
			result[newArrCounter + 2] = '0';
			
			//Update the array counter for the new array
			newArrCounter += 2;
		}

		++newArrCounter;
	}
}

/*
Time Complexity: O(n) -> goes through entire array
Space Complexity: O(1) -> in-place algorithm
*/
void optimized(char input[], int sizeString)
{
	//Start at index 16, but size is 17 for '/0' char
	int j = strlen(input) - 1;

	//Copy from the end, but start at the "real" string
	for (int i = sizeString; i > -1; --i)
	{
		input[j] = input[i];
	
		if (input[i] == ' ')
		{
			input[j] = '0';
			input[j - 1] = '2';
			input[j - 2] = '%';
			j -= 2;
		}

		--j;
	}
}

int main()
{
	char input[18] = "Mr John Smith    ";	
	char result[strlen(input) + 1];

	/*	Brute-force Solution
	bruteForce(input, result);

	cout << result << endl;
	*/

	//Get the last index of the "string"
	int start = strlen(input) - 1;
	while (input[start] == ' ')	
	{
		--start;	
	}

	//Test if start is valid
	cout << start << endl;

	optimized(input, start);
	cout << input << endl;

	return 0;
}
