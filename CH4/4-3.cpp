/*
- List of Depths -
Given a binary tree, design an algorithm which creates a linked list
of all the nodes at each depth (e.g. if you have a tree with depth D,
you'll have D linked lists).

- Hints -
#107, 123, 135
*/

#include <iostream>

using namespace std;

// Assume BST for easier build
struct node
{
	int data;
	node * left;
	node * right;
};

void solutionHelper(node * root, node ** lists, int level);
void solution(node * root, node ** lists);
void insertList(node *& head, int toAdd);
void insert(node *& root, int value);
void print(node * root);

void printList(node ** lists);
void helperPL(node * head);

void insert(node *& root, int value)
{
	if (!root)
	{
		root = new node;
		root -> data = value;
	}
	else if (value > root -> data)
	{
		insert(root -> right, value);	
	}
	else
	{
		insert(root -> left, value);
	}
}

void print(node * root)
{
	if (!root) return;

	cout << root -> data << " ";
	print(root -> left);
	print(root -> right);
}

void solution(node * root, node ** lists)
{
	solutionHelper(root, lists, 0);	
}

// O(n) + O(n) + O(1) averages out to O(N) time complexity
// Space complexity is O(n) to hold the entire tree nodes
void solutionHelper(node * root, node ** lists, int level)
{
	if (!root) return;

	//cout << "Root: " << root -> data << endl;
	//cout << "Level: " << level << endl << endl;

	// O(1) operation	
	insertList(lists[level], root -> data);

	// O(n) recursive stack
	solutionHelper(root -> right, lists, level + 1);
	solutionHelper(root -> left, lists, level + 1);
}

// O(1) insert by adding at the head each time
void insertList(node *& head, int toAdd)
{
	if (!head)
	{
		head = new node;
		head -> data = toAdd;
	}
	else
	{
		node * temp = new node;
		temp -> data = toAdd;
		temp -> right = head;
		head = temp;
	}
}

void printList(node ** lists)
{
	if (!lists) return;

	for (int i = 0; i < 3; ++i)
	{
		helperPL(lists[i]);
		cout << endl;
	}
}

void helperPL(node * head)
{
	if (!head) return;

	cout << head -> data << " ";

	helperPL(head -> right);
}

int main()
{
	node * tree = NULL;
	// Assume we know the height of the tree
	// Declare an array of LLL
	node ** lists = new node * [3];

	insert(tree, 4);
	insert(tree, 2);
	insert(tree, 3);
	insert(tree, 1);
	insert(tree, 6);
	insert(tree, 5);
	insert(tree, 7);

	print(tree);
	cout << endl;

	solution(tree, lists);
	printList(lists);
}
