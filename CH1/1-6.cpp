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
#include <cstdio>
#include <cctype>

using namespace std;

//"*&" -> alias for passing parameter (allows modification)
string to_string(int count);
string bruteForce(string input);

//Convert the frequencies of characters to string
string to_string(int count)
{
	int length = snprintf(NULL, 0, "%d", count);

	char * buffer = new char[length + 1];
	snprintf(buffer, length + 1, "%d", count);
	string freq (buffer);

	return freq;
}

/*
Time Complexity: O(n)
Only goes through string once

Space Complexity: O(n)
Requires extra string for returning the data
*/
string bruteForce(string input)
{
	int len = input.length();

	//Any size less than 2 means that the result str > input str
	if (len < 2) return input;

	string result = "";
	int count = 1;

	for (int i = 0; i < len; ++i)
	{
		//Look-ahead method
		if ((i + 1) < len)
		{
			//Count until a different letter is reached
			if (input[i] == input[i + 1])
			{
				++count;
			}
			else
			{
				//Convert the count to string
				string freq = to_string(count);
				result += input[i] + freq;
				count = 1;	
			}
		}
		else
		{
			string freq = to_string(count);
			result += input[i] + freq;
			if (result.length() >= len) return input;
		}
	}

	return result;
}

int main()
{
	/*Should return a2b1c5a3*/
	string s1 ("aabcccccaaa");

	/*Should return abcd*/
	string s2 ("abcd");

	/*Should return a4b3*/
	string s3 ("aaaabbb");
	
	string r1 = bruteForce(s1);
	string r2 = bruteForce(s2);
	string r3 = bruteForce(s3);

	cout << "(B) Result: " << r1 << endl;
	cout << "(B) Result: " << r2 << endl;
	cout << "(B) Result: " << r3 << endl;

	return 0;
}
