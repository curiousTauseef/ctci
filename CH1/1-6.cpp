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
string optimized(string input);

//Convert the frequencies of characters to string
string to_string(int count)
{
	//Write formatted output to sized buffer
	int length = snprintf(NULL, 0, "%d", count);

	//Create new buffer
	char * buffer = new char[length + 1];

	//Write the number into the buffer
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
			//Handle the case of the last character + freq
			string freq = to_string(count);
			result += input[i] + freq;

			if (result.length() >= len) return input;
		}
	}

	return result;
}

/*
Time Complexity: O(n)
Although nested, we iterate through each data once with two indices
for the algorithm. After iterating through the duplicated chars,
we split the string by beginning, frequency, and end.

Space Complexity: O(1)
Requires no extra space for the algorithm
*/
string optimized(string input)
{
	int len = input.length();

	//Cannot have an input of less than 2 characters
	if (len < 2) return input;

	for (int i = 0; i < len && input[i + 1] != '\0'; ++i)
	{
		//Look-ahead approach
		int count = i + 1;

		//Count all occurences of the number at index i
		while (count < len && input[count] == input[i])
		{
			++count;
		}

		//Make sure to save the frequency count to a string
		string freq = to_string(count - i);

		//Attach the beginning, frequency, and end part without the duplicates
		input = input.substr(0, i + 1) + freq + input.substr(count);

		//Move i over N digits of the frequency number (e.g. 10 -> move 2 indices)
		i += freq.length();
	}	

	return input;
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
	cout << "(B) Result: " << r3 << endl << endl;

	/*End of brute-force solution*/
		
	string r4 = optimized(s1);
	string r5 = optimized(s2);
	string r6 = optimized(s3);

	cout << "(O) Result: " << r4 << endl;
	//cout << "(O) Result: " << r5 << endl;
	//cout << "(O) Result: " << r6 << endl;

	/*End of optimized solution*/

	return 0;
}
