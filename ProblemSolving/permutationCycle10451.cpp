#include <cstdio>

using namespace std;

int purmu[1001];
bool visit[1001];

int main()
{
	int N;
	scanf("%d", &N);

	for (int k = 0; k < N; k++)
	{
		int caseN;
		scanf("%d", &caseN);
		
		for (int i = 1; i <= caseN; ++i)
		{
			scanf("%d", &purmu[i]);
			visit[i] = false;
		}

		int cyclenum = 0;
		for (int i = 1; i <= caseN; ++i)
		{
			int first = i;
			int cur = i;
			while (!visit[cur])
			{
				if (purmu[cur] != first)
				{
					visit[cur] = true;
					cur = purmu[cur];
				}
				else
				{
					cyclenum++;
					break;
				}
			}
		}
		printf("%d\n", cyclenum);
	}
	
	return 0;
}