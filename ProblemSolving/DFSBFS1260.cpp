#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <queue>
using namespace std;

class GraphNode {
public:
	map<int,int> Childs;
	bool isVisit = false;
	void AddChild(int ChildIdx)
	{
		Childs[ChildIdx] = ChildIdx;
	}
};

class infos {
public:
	int NodeIdx;
	map<int, int>::iterator iter;
	map<int, int>::iterator iterend;
	infos(int idx, map<int, int>::iterator NextChild, map<int, int>::iterator end):NodeIdx(idx), iter(NextChild), iterend(end)
	{
	}
};

void DFS(vector<GraphNode>& Graph, int start)
{
	stack<infos> st;
	printf("%d ", start);
	Graph[start].isVisit = true;
	st.push(infos(start, Graph[start].Childs.begin(), Graph[start].Childs.end()));
	
	while (st.size()>0)
	{
		infos& sn = st.top();
		if (sn.iter == sn.iterend)
		{
			st.pop();
			continue;
		}
		if (!Graph[sn.iter->first].isVisit)
		{
			printf("%d ", sn.iter->first);
			Graph[sn.iter->first].isVisit = true;
			st.push(infos(sn.iter->first, Graph[sn.iter->first].Childs.begin(), Graph[sn.iter->first].Childs.end()));
		}
		sn.iter++;		
	}
}

void BFS(vector<GraphNode>& Graph, int start)
{
	queue<int> q;
	printf("%d ", start);
	Graph[start].isVisit = true;
	for (auto a : Graph[start].Childs)
	{
		q.push(a.first);
	}	
	while (q.size() > 0)
	{
		int qfront = q.front();
		q.pop();
		if (!Graph[qfront].isVisit)
		{
			printf("%d ", qfront);
			Graph[qfront].isVisit = true;
			for (auto a : Graph[qfront].Childs)
			{
				q.push(a.first);
			}
		}
	}
}


int main()
{
	int n, e, first;
	scanf("%d %d %d", &n, &e, &first);
	int a, b;
	vector<GraphNode> Graph(n+1);
	for (int i = 0; i < e; ++i)
	{		
		scanf("%d %d", &a, &b);
		Graph[a].AddChild(b);
		Graph[b].AddChild(a);
	}

	DFS(Graph, first);
	printf("\n");
	for (int i = 1 ; i<= n; ++i)
	{
		Graph[i].isVisit = false;
	}
	BFS(Graph, first);

	return 0;
}