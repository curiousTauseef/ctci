/*
- Route Between Nodes -
Given a directed graph, design an algorithm to find out whether
there is a route (path) between 2 nodes.

- Answer -
Either use BFS or DFS to find the desired node along the path

- Hints -
#127
*/

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

struct vertex
{
	int data;
	struct node * head;
};

struct node
{
	vertex * adjacent;
	node * next;
};

void build(vertex *& graph);
void display(vertex *& graph);
void displayRec(node * head);
void insertEdge(vertex *& graph, int one, int two);
bool hasRoute(vertex * graph, int one, int two);

//Basic DFS Algorithm
void DFS(vertex * graph, int v);
void helperDFS(vertex * graph, int v, bool visited[]);
int getIndex(vertex * graph, int toFind);

void BFS(vertex * graph, int index);

void build(vertex *& graph)
{
	int array[5] = {2, 4, 6, 8, 10};

	for (int i = 0; i < 5; ++i)
	{
		graph[i].data = array[i];
	}
}

void display(vertex *& graph)
{
	for (int i = 0; i < 5; ++i)
	{
		cout << graph[i].data << " ";
		displayRec(graph[i].head);
		cout << endl;
	}
}

void displayRec(node * head)
{
	if (!head) return;

	cout << head -> adjacent -> data << " ";

	return displayRec(head -> next);
}

void insertEdge(vertex *& graph, int one, int two)
{
	node * temp = new node;
	temp -> next = graph[one].head;
	graph[one].head = temp;
	temp -> adjacent = &graph[two];
}

bool hasRoute(vertex * graph, int one, int two)
{
	bool * visited = new bool[5];

	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
	}

	stack<int> myStack;
	myStack.push(one);
	visited[one] = true;

	int currV = one;
	node * start = graph[currV].head;

	while (!myStack.empty())
	{
		currV = myStack.top();
		myStack.pop();

		while (start)
		{
			currV = getIndex(graph, start -> adjacent -> data);

			if (visited[two]) return true;
			if (!visited[currV])
			{
				cout << start -> adjacent -> data << " ";
				myStack.push(currV);
				visited[currV] = true;
			}

			start = start -> next;
		}

		//Update the graph vertex after reading each neighbor
		start = graph[currV].head;
	}

	return false;
}

void DFS(vertex * graph, int v)
{
	bool * visited = new bool[5];

	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
	}

	helperDFS(graph, v, visited);
}

void helperDFS(vertex * graph, int v, bool visited[])
{
	visited[v] = true;
	cout << graph[v].data << " ";

	node * start = graph[v].head;

	while (start)
	{
		v = getIndex(graph, start -> adjacent -> data);

		if (!visited[v])
		{
			helperDFS(graph, v, visited);
		}

		start = start -> next;
	}
}

int getIndex(vertex * graph, int toFind)
{
	for (int i = 0; i < 5; ++i)
	{
		if (graph[i].data == toFind) return i;
	}
}

void BFS(vertex * graph, int index)
{
	bool * visited = new bool[5];
	for (int i = 0; i < 5; ++i)
	{
		visited[i] = false;
	}

	queue<int> myQueue;
	myQueue.push(index);
	visited[index] = true;
	node * start = graph[index].head;
	int curr = 0;

	cout << graph[index].data << endl;

	while (!myQueue.empty())
	{
		curr = myQueue.front();
		myQueue.pop();

		while (start)
		{
			curr = getIndex(graph, start -> adjacent -> data);
			cout << start -> adjacent -> data << endl;

			if (!visited[curr])
			{
				visited[curr] = true;
				myQueue.push(curr);
			}

			start = start -> next;
		}

		start = graph[curr].head;
	}
}

int main()
{
	vertex * graph = new vertex[5];
	build(graph);
	insertEdge(graph, 0, 1);
	insertEdge(graph, 2, 3);
	insertEdge(graph, 1, 4);
	insertEdge(graph, 4, 2);
	//insertEdge(graph, 4, 0);
	//insertEdge(graph, 0, 4);
	//insertEdge(graph, 4, 2);
	display(graph);
	cout << "----------------" << endl;
	BFS(graph, 0);
	//DFS(graph, 0);
	//cout << endl;
	//(hasRoute(graph, 3, 2) == 1) ? cout << "There's a path!" << endl : cout << "No path!" << endl;
}
