#pragma once
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

void DFS()
{
	int n, e;
	scanf("%d %d", &n, &e);
	vector<map<int, int>> Graph(n + 1);
	int a, b;
	for (int i = 0; i < e; ++i)
	{
		scanf("%d %d", &a, &b);
		Graph[a][b] = b;
		Graph[b][a] = a;
	}

	vector<int> VisitTable(n + 1, 0);
	if (RecurDFS(Graph, 1, 1, VisitTable)) printf("YES\n");
	else printf("NO\n");
}

bool RecurDFS(vector<map<int, int>>& Graph, int CurNode, int kind, vector<int>& VisitTable)
{
	if (!VisitTable[CurNode])
	{
		if (VisitTable[CurNode] != kind) return false;
		return true;
	}
	VisitTable[CurNode] = kind;
	for (auto Child : Graph[CurNode])
	{
		if (!RecurDFS(Graph, Child.first, -1 * kind, VisitTable)) return false;
	}
	return true;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++n)
	{
		DFS();
	}	
	return 0;
}

