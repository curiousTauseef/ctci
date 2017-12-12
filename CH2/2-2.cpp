/*
- Return K'th to Last -
Implement an algorithm to find the k'th to last element of an LLL

e.g. 1 -> 2 -> 3 -> 4 -> 5
k = 2, so returns 4

- Hints -

#8
#25
#41
#67
#126
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

int findKTH(node * list, int & result, int value);

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

// O(N)
// Utilizes backtracking recursion and stores the k'th
// value into the passed-by-reference result
int findKTH(node * list, int & result, int value)
{
	if (!list) return 0;

	int counter = findKTH(list -> next, result, value);

	if (counter == value)
	{
		result = list -> data;
	}

	return ++counter;
	
}

int main()
{
	node * list = NULL;

	build(list, 5);
	build(list, 4);
	build(list, 3);
	build(list, 2);
	build(list, 1);

	print(list);
	int kValue;
	findKTH(list, kValue, 2);

	cout << "K'th value: " << kValue << endl;

	destroy(list);
	return 0;
}
