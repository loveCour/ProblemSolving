#include <cstdio>
#include <vector>
using namespace std;

static const int SIZE = 3200;
int main()
{
	int n;
	scanf("%d", &n);

	bool table[SIZE];
	vector<int> primes;
	for (int i = 2; i < SIZE; ++i)
	{
		table[i] = true;
	}
	for (int i = 2; i*i < SIZE; ++i)
	{
		if (!table[i])
		{
			continue;
		}
		for (int j = i + i; j < SIZE; j += i)
		{
			table[j] = false;
		}
	}

	primes.push_back(2);
	for (int i = 3; i < SIZE; i += 2)
	{
		if (table[i])
		{
			primes.push_back(i);			
		}
	}
	
	int primesize = primes.size();
	for (int i = 0; i < primesize; i++)
	{
		while (n % primes[i] == 0)
		{
			n /= primes[i];
			printf("%d\n", primes[i]);
			if (n == 1)
			{
				break;
			}
		}
	}
	if (n != 1)
	{
		printf("%d\n", n);
	}
	return 0;
}