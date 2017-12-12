/*
- Partition -
Write code to partition a linked list around a value x,
such that all nodes less than x come before nodes greater
than or equal to x. The partition element x can appear
anywhere in the "right position"; it does not need to
appear between the left and right partitions.

- EXAMPLE -
1 -> 4 -> 3 -> 2 -> 5 -> 2 (x = 3)
1 -> 2 -> 2 -> 4 -> 3 -> 5

- HINTS -
#3, #24
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

void partition(node *& list, node *& newList, int pValue);
void addEnd(node *& newList, int data);

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

/* Time Complexity Analysis
 * Partition function goes through list one time O(N)
 * Adding @ the end function occurs on average O(N/2) times
 * On average, the time complexity should be O(N)
 *
 * Space Complexity Analysis
 * Building a new list, so it takes O(N) extra space
 */
void partition(node *& list, node *& newList, int pValue)
{
	if (!list) return;

	node * curr = list;

	while (curr)
	{
		if (curr -> data < pValue)
		{
			if (!newList)
			{
				node * temp = new node;
				temp -> data = curr -> data;
				newList = temp;
			}
			else
			{
				int oldHead = newList -> data;
				newList -> data = curr -> data;
				node * temp = new node;
				temp -> data = oldHead;
				temp -> next = newList;
				newList = temp;
			}
		}
		else
		{
			addEnd(newList, curr -> data);
		}

		curr = curr -> next;
	}	
}

void addEnd(node *& newList, int data)
{
	if (!newList) return;
	
	if (!newList -> next)
	{
		node * temp = new node;
		temp -> data = data;
		newList -> next = temp;
		return;
	}

	addEnd(newList -> next, data);
}

int main()
{
	node * list1 = NULL;
	node * list2 = NULL;

	// Problem set #1
	/*
	build(list1, 2);
	build(list1, 5);
	build(list1, 2);
	build(list1, 3);
	build(list1, 4);
	build(list1, 1);
	*/

	// Problem set #2
	build(list1, 1);
	build(list1, 2);
	build(list1, 10);
	build(list1, 5);
	build(list1, 8);
	build(list1, 5);
	build(list1, 3);

	partition(list1, list2, 5);
	print(list1);
	print(list2);
	destroy(list1);
	destroy(list2);

	return 0;
}
