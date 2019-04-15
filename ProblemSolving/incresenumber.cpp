#include <iostream>

using namespace std;

int dptable[1001][10];

int main()
{
	int n;
	int mod = 10007;
	cin >> n;

	for (int j = 0; j < 10; j++)
	{
		dptable[1][j] = 1;
	}

	for (int i = 2; i <= n; ++i)
	{		
		for (int j = 0; j < 10; ++j)
		{
			dptable[i][j] = 0;
			for (int k = 0; k <= j; ++k)
			{
				dptable[i][j] += dptable[i-1][k];				
			}
			dptable[i][j] %= mod;
		}
	}
	int result = 0;
	for (int i = 0; i < 10; i++)
	{
		result += dptable[n][i];
	}
	cout << result % mod;
	return 0;
}
