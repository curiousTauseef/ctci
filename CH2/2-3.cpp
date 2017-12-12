/*
- Delete Middle Node -
Implement an algorithm to delete a node in the middle
(i.e., any node but the first and last node, not
necessarily the exact middle) of a singly linked list,
given only access to that node.

- EXAMPLE -
Input: (node c) a -> b -> c -> d -> e -> f
Output: Nothing returned, but new list is a -> b -> d -> e -> f

- HINTS -
#72
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

void deleteMid(node *& list, int & items, int & counter);

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

// O(N) time complexity with O(1) space complexity
// Count the items on the way up, and then delete on the way down
void deleteMid(node *& list, int & items, int & counter)
{
	if (!list) return;

	++items;

	deleteMid(list -> next, items, counter);

	if ( (items / 2) == counter)
	{
		node * temp = list -> next;
		//cout << temp -> data << endl;
		//cout << list -> data << endl;
		delete list;
		list = temp;
	}

	++counter;
}

int main()
{
	node * list = NULL;

	build(list, 5);
	build(list, 4);
	build(list, 3);
	build(list, 2);
	build(list, 1);

	int items = 0, counter = 0;
	deleteMid(list, items, counter);
	print(list);
	destroy(list);
	return 0;
}
