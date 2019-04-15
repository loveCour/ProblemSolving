#include <cstdio>
#include <vector>
using namespace std;

static const int SIZE = 1000001;
int main()
{
	bool table[SIZE];
	vector<int> primes;
	table[2] = true;
	table[3] = true;
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
	for (int i = 3; i < SIZE; i += 2)
	{
		if (table[i])
		{
			primes.push_back(i);
		}
	}

	int testcase = -1;
	while (testcase != 0)
	{
		scanf("%d", &testcase);
		for (int i = 0; primes[i] <= testcase/2; ++i)
		{
			if (table[testcase - primes[i]])
			{
				printf("%d = %d + %d\n", testcase, primes[i], testcase - primes[i]);
				break;
			}
		}
	}
	return 0;
}