/*
- Palindrome -
Implement a function to check if a linked list is a palindrome.

e.g. 1 2 2 1 (even palindrome)
e.g. 1 3 1 (odd palindrome)
e.g. 1

- HINTS - 
#5, 13, 29, 61, 101

- FOLLOW-UP -
Solve this in O(N) time complexity and O(1) space complexity
*/

#include <iostream>

using namespace std;

struct node
{
	int data;
	node * next;
};

void build(node *& list, int data);
void destroy(node *& list);
void print(node * list);

bool palindrome(node * list, int & size, int & realSize, int *& array);
bool check(int * array, int realSize);

void build(node *& list, int data)
{
	if (!list)
	{
		list = new node;
		list -> data = data;
	}
	else
	{
		node * temp = new node;
		temp -> data = data;
		temp -> next = list;
		list = temp;
	}
}

void destroy(node *& list)
{
	if (!list) return;

	destroy(list -> next);

	delete list;
	list = NULL;
}

void print(node * list)
{
	if (!list) return;

	if (!list -> next)
	{
		cout << list -> data << endl;
		return;
	}

	cout << list -> data << " -> ";

	print(list -> next);
}

bool palindrome(node * list, int & size, int & realSize, int *& array)
{
	if (!list) return true;

	palindrome(list -> next, ++size, realSize, array);

	if (!array)
	{
		realSize = size;
		array = new int[size];
		array[size - 1] = list -> data;
		--size;
	}
	else
	{
		array[size - 1] = list -> data;
		--size;
	}

	if (size == 0)
	{
		return check(array, realSize);
	}

	return false;
}

bool check(int * array, int realSize)
{
	if (realSize == 1) return true;

	int i = 0, j = 0;

	if (realSize % 2 == 0)
	{
		i = (realSize / 2) - 1;
		j = i + 1;

	}
	else
	{
		i = (realSize / 2);
		j = i;
	}

	while (i >= 0 && j <= realSize)
	{
		if (array[i] != array[j])
		{
			return false;
		}

		--i;
		++j;
	}

	return true;
}

int main()
{
	node * list = NULL;
	
	build(list, 1);
	build(list, 2);
	build(list, 3);
	build(list, 3);
	build(list, 2);
	build(list, 1);

	int size = 0, realSize = 0;
	int * array = NULL;
	bool isPalindrome = palindrome(list, size, realSize, array);

	cout << "Is the list a palindrome? ";	
	(isPalindrome == 1) ? cout << "True" << endl: cout << "False" << endl;

	/*
	for (int i = 0; i < 4; ++i)
	{
		cout << array[i] << endl;
	}
	*/
	print(list);	
	destroy(list);
	return 0;
}
