/*
- SUM LISTS -
You have 2 numbers represented by a linked list, where each node
contains a single digit. The digits are stored in reverse order,
such that the 1's digit is at the head of the list. Write a
function that adds the 2 numbers and returns the sum as a linked
list.

- EXAMPLE -
Input: (7 -> 1 -> 6) + (5 -> 9 -> 2). That is, 617 + 295.
Output: 2 -> 1 -> 9. That is, 912.

- FOLLOW UP - (basically same thing)
Suppose the digits are stored in forward order. Repeat the above
pattern.

- EXAMPLE -
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5). That is, 617 + 295.
Output: 9 -> 1 -> 2. That is, 912.

- HINTS -
#7,30,71,95,109
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

int solution(node * list, int & multiplier);

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

// O(n) + O(m) time complexity and O(1) space complexity
// Easy problem
int solution(node * list, int & multiplier)
{
	if (!list) return 0;

	int total = list -> data * multiplier;
	multiplier *= 10;

	//int total = solution(list -> next, multiplier);

	//total += multiplier * list -> data;
	//multiplier /= 10;

	return total + solution(list -> next, multiplier);	
}

int solution2(node * list, int & multiplier)
{
	if (!list) return 0;
}

int main()
{
	node * list1 = NULL, * list2 = NULL;

	build(list1, 6);
	build(list1, 1);
	build(list1, 7);

	build(list2, 2);
	build(list2, 9);
	build(list2, 5);

	int multiplier = 1;

	int total = solution(list1, multiplier);
	multiplier = 1;
	total += solution(list2, multiplier);

	cout << "Total: " << total << endl;

	destroy(list1);
	destroy(list2);

	return 0;
}
