#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &E);
bool checkExists(unordered_set<int> &visitedRoots, int x, int y);
void print(vector<int> &A, vector<int> &E);

bool checkExists(unordered_set<int> &visitedRoots, int x, int y)
{
	if (visitedRoots.find(x) != visitedRoots.end() ||
		visitedRoots.find(y) != visitedRoots.end())
	{
		return true;
	}	

	return false;
}
//Undirected tree represented as two vectors
int solution(vector<int> &A, vector<int> &E)
{
	if (A.size() == 1) return 0;

	unordered_set<int> longPath = {};
	unordered_set<int> visitedRoots = {};
	int i = 0, j = 0, x = 0, y = 0;
	int largestPath = 0;

	for (; i < E.size(); i += 2)
	{	
		for (x = i, y = x + 1; x < E.size() && y < E.size(); x += 2, y = x + 1)
		{	
			//cout << "Pair Values: " << E[x] << "," <<  E[y] << endl;
			//cout << "Label Values: " << A[E[x] - 1] << "," <<  A[E[y] - 1] << endl;	

			int xLabelVal = E[x] - 1;
			int yLabelVal = E[y] - 1;

			if (visitedRoots.empty() && A[xLabelVal] == A[yLabelVal])
			{	
				//cout << "Pair Values: " << E[x] << "," <<  E[y] << endl;
				visitedRoots.insert({E[x], E[y]});
			}
			else if (A[xLabelVal] == A[yLabelVal] && checkExists(visitedRoots, E[x], E[y]))
			{
				//cout << "Pair Values: " << E[x] << "," <<  E[y] << endl;
				visitedRoots.insert({E[x], E[y]});
			}
		}

		if ((visitedRoots.size() - 1) > largestPath && !visitedRoots.empty())
		{
			longPath = visitedRoots;
			largestPath = visitedRoots.size() - 1;	
		}

		visitedRoots = {};
		//cout << "-------" << endl;
	}

	cout << "Nodes on the path" << endl;

	for (int a : longPath)
	{
		cout << a << endl;
	}
	

	return largestPath;
}


void print(vector<int> &A, vector<int> &E)
{
	cout << "Connected Edges: ";

	for (int i = 0; i < E.size(); ++i)
	{
		cout << E[i] << " ";
	}	

	cout << endl;

	cout << "1 .. N values with respective labels: ";

	for (int j = 0; j < A.size(); ++j)
	{
		cout << A[j] << " ";
	}

	cout << endl << endl;
}

int main()
{
	vector<int> A;
	vector<int> E;

	/* Test Case #1
	int arr1 [] = {1, 1, 1, 2, 2};
	int arr2 [] = {1, 2, 1, 3, 2, 4, 2, 5};

	A.insert(A.begin(), arr1, arr1 + 5);
	E.insert(E.begin(), arr2, arr2 + 8);
	*/	

	/* Test Case #2
	*/
	int arr3 [] = {2, 2, 1, 3, 3, 1, 1};
	int arr4 [] = {1, 2, 1, 3, 2, 4, 2, 5, 3, 6, 3, 7};

	A.insert(A.begin(), arr3, arr3 + 7);
	E.insert(E.begin(), arr4, arr4 + 12);
	
	print(A, E);

	int longestPath = solution(A, E);	
	cout << "The longest path in this tree is: " << longestPath << endl;
}
