/*
URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the "true"
length of the string. Try to do this algorithm in-place.

EXAMPLE
Input:  "Mr John Smith    ", 13
Output: "Mr%20John%20Smith"

HINTS
#53: It's often easiest to modify strings by going from the end of the string to the beginning
Filling in the contents of the "true array" starting at the extra space to the front is the
most efficient algorithm.

#118: You might find out that you need to know the number of spaces. Can you just count them?
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	char input[18] = "Mr John Smith    ";
	return 0;
}
