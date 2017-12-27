/*
- Minimal Tree -
Given a sorted (increasing order) array with unique integer
elements, write an algorithm to create a binary search tree
with minimal height.

- Answer -
Basically the question is asking us to simply balance the tree.
This means that 7 nodes should have an optimal height of
3, or 2^3 - 1 = 7. An optimal solution would be to use the AVL
tree insertion method.

- Hints -
#19, 73, 116
*/

#include <iostream>
#include <cmath>

using namespace std;

struct node
{
	int data;
	node * left;
	node * right;
};

void display(node * BST);
void rotateLeft(node *& BST);
void insert(node *& BST, int value);
node * createMinTree(int array[]);

void display(node * BST)
{
	if (!BST) return;

	cout << BST -> data << " ";
	display(BST -> left);
	display(BST -> right);
}


// O(1) Time Complexity insertion
void insert(node *& BST, int value)
{
	if (!BST)
	{
		BST = new node;
		BST -> data = value;
	}
	else
	{
		node * temp = new node;
		temp -> data = value;
		temp -> right = BST;
		BST = temp;
	}
}

void rotateLeft(node *& BST)
{
	if (!BST) return;

	if (!BST -> left && !BST -> right) return;

	node * x = BST;
	node * y = BST -> right;
	node * T1 = x -> left;
	node * T2 = y -> left;
	node * T3 = T3 = y -> right;

	x -> right = T2;
	y -> left = x;	
	BST = y;
}

node * createMinTree(int array[], int size)
{
	node * BST = NULL;

	// Insert all the arrays into the tree
	for (int i = size - 1; i >= 0; --i)
	{
		insert(BST, array[i]);	
	}

	// Gives you minimum height
	int height = log2(size) + 1;

	// Calculate lowest level nodes, which is equivalent to the # of left initial left rotations
	int initialRotates = (size != pow(2, height) - 1) ? size - (pow(2, height - 1) - 1) : 0;
	cout << initialRotates << endl;

	node * init = BST;

	// Rotate every odd node in the tree with the above calculation
	for (int j = 0; j < initialRotates; ++j)
	{
		if (j == 0)
		{
			rotateLeft(init);
			BST = init;
		}
		else
		{
			rotateLeft(init -> right);
			init = init -> right;
		}
	}
	
	// Rotate every other node in the tree size / 2 times until size equals 1
	int count = 0;
	while (size > 1)
	{
		// Rotate the root (first odd node)
		size /= 2;
		rotateLeft(BST);
		node * curr = BST;

		// Return BST if it's not a perfectly balanced tree
		if (size == 2) return BST;

		// Rotate the rest of the odd nodes
		for (int k = 0; k < (size - 1); k++)
		{
			rotateLeft(curr -> right);
			curr = curr -> right;
		}

	}

	// Return the BST if it's exactly 2^H - 1 = 7 for e.g.
	return BST;
}

int main()
{
	node * BST = NULL;
	int array[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	BST = createMinTree(array, 15);
	display(BST);
}
