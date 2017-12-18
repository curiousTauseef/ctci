/*
- Three in One -
Describe how you could use a single array to implement 3 stacks.

- Answer -
Create a stack class. Initialize the class pointer to 3 stacks.
Allocate an array in each stack class.

- Hints -
#2, 12, 38, 58
*/

#include <iostream>

using namespace std;

class stack
{
	public:
		stack(int * arr, int size);
		~stack();

		void print();
		void push(int val);
		void pop();

	private:
		int * array;
		int arrSize;
};

stack::stack(int * arr, int size)
{
	arrSize = size;
	array = new int[size];

	for (int i = 0; i < size; ++i)
	{
		array[i] = arr[i];
	}
}

stack::~stack()
{
	if (array)
	{
		delete [] array;
	}
}

void stack::print()
{
	if (array)
	{
		for (int i = 0; i < arrSize; ++i)
		{
			cout << array[i] << " ";
		}

		cout << endl;
	}
}

void stack::push(int val)
{
	for (int i = 0; i < arrSize; ++i)
	{
		if (array[i] == 0)
		{
			array[i] = val;
			return;
		}
	}	
}

void stack::pop()
{
	for (int i = arrSize - 1; i >= 0; --i)
	{
		if (array[i] != 0)
		{
			array[i] = 0;		
			return;
		}
	}
}

int main()
{
	int array [] = {1, 2, 3, 4, 5};

	stack myStack[3] = 
	{
		stack(array, 5),
		stack(array, 4),
		stack(array, 3)
	};

	// Executing essential stack operations
	myStack[0].pop();
	myStack[0].push(6);

	for (int i = 0; i < 3; ++i)
	{
		myStack[i].print();
	}
}
