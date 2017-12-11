#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> &A, vector<int> &E);

//Undirected tree represented as two vectors
int solution(vector<int> &A, vector<int> &E)
{

}

int main()
{
	vector<int> A;
	vector<int> E;

	int arr1 [] = {1, 1, 1, 2, 2};
	int arr2 [] = {1, 2, 1, 3, 2, 4, 2, 5};

	A.insert(A.begin(), arr1, arr1 + 5);
	E.insert(E.begin(), arr2, arr2 + 8);

	/*
	for (int i = 0; i < E.size(); ++i)
	{
		cout << E[i] << " ";
	}	
	*/
}
