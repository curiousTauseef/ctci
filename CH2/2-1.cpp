/*
- Remove Dups -
Write code to remove duplicates from an unsorted linked list of integers.
(Assume not sorted)

FOLLOW UP (Required: O(1) Space Complexity)
How would you solve this problem if a temporary buffer is not allowed?
Solved the problem with recursion instead of allocating a MAX_INT array of integers.
Two more possible solutions:
1. Sort the list then delete in linear fashion
2. Use unordered set
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

void removeDups(node *& list);
void rdHelper(node *& list, int value);

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

void removeDups(node *& list)
{
	if (!list || !list->next) return;

	//Use temporary pointer to keep existing list
	node * temp = list;

	//Loop until temp is NULL
	while (temp)
	{
		//Compare the rest of the nodes
		rdHelper(temp -> next, temp -> data);
		temp = temp -> next;
	}
}

void rdHelper(node *& list, int value)
{
	if (!list) return;

	if (list -> data == value)
	{
		//Delete the node that has non-null next pointer
		if (list -> next)
		{
			node * temp = list -> next;
			delete list;
			list = temp;	
		}
		//Delete the node that has null next pointer
		else
		{
			delete list;
			list = NULL;
			return;
		}
	}	
	
	rdHelper(list -> next, value);
}

int main()
{
	node * list = NULL;

	/*
	build(list, 5);
	build(list, 3);
	build(list, 3);
	build(list, 2);
	build(list, 2);
	build(list, 5);
	build(list, 5);
	*/

	build(list, 1);
	build(list, 1);
	build(list, 2);
	build(list, 2);
	build(list, 3);
	build(list, 3);

	removeDups(list);
	print(list);
	destroy(list);

	return 0;
}
