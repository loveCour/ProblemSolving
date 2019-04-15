#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n;
	int input[1000];
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> input[i];
	}
	
	map<int, int> tree;	
	tree[input[0]] = 1;	
	int max = 1;

	for (int i = 1; i < n; i++)
	{
		tree[input[i]] = 1;
		auto previousNode = tree.find(input[i]);
		previousNode--;
		if (previousNode != tree.end())
		{
			max = (max > previousNode->second + 1)?  max : previousNode->second + 1;
			tree[input[i]] = previousNode->second + 1;
		}
	}
	cout << max;
	return 0;
}
