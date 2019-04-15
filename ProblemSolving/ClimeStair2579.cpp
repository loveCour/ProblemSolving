#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	int input[301];
	int dp[301];
	input[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> input[i];
	}
	dp[0] = 0;
	dp[1] = input[1];
	dp[2] = input[1] + input[2];

	for (int i = 3; i <= n; ++i)
	{
		int tmp = dp[i - 3] + input[i - 1];
		dp[i] = (tmp > dp[i - 2]) ? tmp : dp[i - 2];
		dp[i] += input[i];
	}
	cout << dp[n];
	return 0;
}