#pragma once
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

class GraphNode {
public:
	map<int,int> Childs;
	void AddChild(int ChildIdx)
	{
		Childs[ChildIdx] = ChildIdx;
	}
};

void DFS(vector<GraphNode>& Graph, int Start, int NodeNum)
{
	stack<int> st;
	vector<bool> VisitTable(NodeNum, false);
	st.push(Start);

	while (!st.empty())
	{
		int CurNode = st.top();
		st.pop();
		if (!VisitTable[CurNode])
		{
			VisitTable[CurNode] = true;
			for (auto child : Graph[CurNode].Childs)
			{
				st.push(child.first);
			}
		}
	}
}

void BFS(vector<GraphNode>& Graph, int Start, int NodeNum)
{
	queue<int> q;
	vector<bool> VisitTable(NodeNum, false);
	q.push(Start);

	while (!q.empty())
	{
		int CurNode = q.front();
		q.pop();
		if (!VisitTable[CurNode])
		{
			VisitTable[CurNode] = true;
			for (auto child : Graph[CurNode].Childs)
			{
				q.push(child);
			}
		}
	}
}