/*
- Sort Stack -
Write a program to sort a stack such that the smallest items are on the top. 
You can use an additional temporary stack, but you may not copy the elements 
into any other data structure ( such as an array). The stack supports the 
following operations: push, pop, peek, and isEmpty.

- Hints -
#15, 32, 43
*/

#include <iostream>

using namespace std;

struct stack
{
	int data;
	stack * next;
};

void push(stack *& S, int val);
int pop(stack *& S);
int peek(stack * S);
bool isEmpty(stack * S);
void print(stack * S);

void sortStack(stack *& s);
void sortHelper(stack *& s, int value);

// Solution with O(1) extra space (no data structures) excluding recursive call space
void sortStack(stack *& s)
{
	if (s)
	{
		int temp = pop(s);
		sortStack(s);
		sortHelper(s, temp);
	}
}

void sortHelper(stack *& s, int value)
{
	if (isEmpty(s) || value < peek(s))
	{
		push(s, value);
	}
	else
	{
		int temp = pop(s);
		sortHelper(s, value);
		push(s, temp);
	}
}

// Push at the head "top"
void push(stack *& S, int val)
{
	if (!S)
	{
		S = new stack;
		S -> data = val;
		return;
	}

	stack * temp = new stack;
	temp -> data = val;
	temp -> next = S;
	S = temp;
}

// Remove at the head "top"
int pop(stack *& S)
{
	if (!S)
	{
		return 0;
	}

	int topVal = S -> data;
	stack * save = S -> next;
	delete S;
	S = save;

	return topVal;
}

int peek(stack * S)
{
	if (!S)
	{
		return 0;
	}

	return S -> data;
}

bool isEmpty(stack * S)
{
	bool flag;

	(!S) ? flag = true : flag = false;

	return flag;
}

void print(stack * S)
{
	if (!S) return;

	stack * curr = S;

	while (curr)
	{
		cout << curr -> data << " ";
		curr = curr -> next;
	}
	
}

int main()
{
	stack * myStack = NULL;

	push(myStack, 40);
	push(myStack, -2);
	push(myStack, 16);
	push(myStack, 15);
	push(myStack, -1);

	sortStack(myStack);
	print(myStack);
	cout << endl;
}
