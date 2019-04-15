#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int dp[100001];

	int LargestRoot = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (i == (LargestRoot+1) * (LargestRoot+1))
		{
			dp[i] = 1;
			++LargestRoot;
			continue;
		}
		int Min = 2147483647;
		for (int CurRoot = 1; CurRoot <= LargestRoot; ++CurRoot)
		{
			int Tmp = dp[i - CurRoot * CurRoot] + 1;
			Min = (Min < Tmp) ? Min : Tmp ;
		}
		dp[i] = Min;
	}
	cout << dp[n];
	return 0;
}