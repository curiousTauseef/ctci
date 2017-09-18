/*
- String Compression -
Implement a method to perform basic string compression using the counts
of repeated characters. 

For example, the string "aabcccccaaa" would become "a2b1c5a3". If the
"compressed" string would not become smaller than the original string,
your method should return the original string.

You can assume the string has only uppercase and lowercase letters
(a -z).

- TWIST -
To make things harder, assume that we have NO SPACE. This means that
this algorithm must be done in place. -Amazon SE Question : Glassdoor
*Given that the input string will not result in a larger string
*Allowed usage of <string> library

- Hints -

#92: Do the easy thing first: compress the string, then compare lengths.

#110: Be careful that you aren't repeatedly concatenating strings
together. This can be very inefficient.

*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//"*&" -> alias for passing parameter (allows modification)
string bruteForce(string input);

string bruteForce(string input)
{

}

int main()
{
	/*Should return a2b1c5a3*/
	string s1 = "aabcccccaaa";

	/*Should return abcd*/
	string s2 = "abcd";

	/*Should return abca3b3*/
	string s3 = "abcaaabbb";

	bruteForce(s1);

	return 0;
}
