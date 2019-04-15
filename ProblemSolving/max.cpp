#include <iostream>

using namespace std;

int main()
{
	int n;
	int max = 0;
	int gainValue = 0;
	int curNum;
	cin >> n;
	cin >> curNum;
	max = gainValue = curNum;
	for (int i = 1; i < n; ++i)
	{
		cin >> curNum;
		if (gainValue > 0)
		{
			gainValue += curNum;
		}
		else
		{
			gainValue = curNum;
		}
		max = (max > gainValue)? max : gainValue;
	}
	
	cout << max;
	return 0;
}
