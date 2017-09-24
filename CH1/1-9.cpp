/*
- String Rotation -
Assume you have a method "isSubstring" which checks if one word
is a substring of another. Given 2 strings, s1 and s2, write
code to check if s2 is a rotation of s1 using only one call
to "isSubString".

(e.g. "waterbottle" is a rotation of "erbottlewat")

- Hints -

#34: A string is a rotation of another, then it's a rotation at
a particular point. For example, a rotation of waterbottle at
stringacter 3 means cutting waterbottle at stringacter 3 and
putting the right half (erbottle) before the left half (wat).

#88: We are essentially asking if there's a way of splitting
the first string into 2 parts, x and y, such that the 1st
string is xy and the 2nd string is yx. For example, x = wat
and y = erbottle. The 1st string is xy = waterbottle. The
2nd string is yx = erbottlewat.

#104: Think about the earlier hint. Then think about what
happens when you concatenate erbottlewat to itself. You
get erbottlewaterbottlewat.

*/

#include <iostream>
#include <string>

using namespace std;

bool rotateStr(string s1, string s2);

/*
Time Complexity: ~O(n^2)
A custom find() function would most likely be O(n^2) depending on the
implementation. 


Space Complexity: O(s1 + s1)
Requires O(n) space, or double the first input which is equal to the 2nd
*/
bool rotateStr(string s1, string s2)
{
	if (s1.length() != s2.length()) return false;

	//Duplicate s1 2x into single string
	string doubleStr1 = s1 + s1;

	//Search for the matching 
	size_t found = doubleStr1.find(s2);

	if (found == -1) return false;

	return true;
}

int main()
{
	string s1 = "waterbottle";
	string s2 = "erbottlewat";

	bool isRotation = rotateStr(s1, s2);

	cout << "Is rotation? " << isRotation << endl;	

	return 0;
}
