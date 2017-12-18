/*
- Stack Min -
How would you design a stack which, in addition to push and pop, has a function min which returns the minimum element? Push, pop, and min should all operate in O(1) time.

-Answer-
To reduce swapping, I'd implement a linear linked list. The push and pop would happen at the
list's head pointer. The class would have a private data member to keep track of the minimum
value, so the min() simply returns that data member.

- Hints -
#27, 59, 78
*/

#include <iostream>

using namespace std;

int main()
{

}
