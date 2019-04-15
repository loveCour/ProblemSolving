#include <iostream>

using namespace std;
int main()
{
	int n;
	cin >> n;
	if (n % 2 != 0)
	{
		cout << 0;
	}
	else if (n == 2)
	{
		cout << 3;
	}
	else if (n == 4)
	{
		cout << 11;
	}
	else
	{
		int result = pow(3, n / 2 - 2);
		cout <<  result * 11 + 8 * (result - 1) / 2;
	}	
	return 0;
}