#include <cstdio>
#include <vector>
#include <map>
#include <stack>
using namespace std;

class GraphNode {
public:
	map<int, int> Childs;
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
	infos(int idx, map<int, int>::iterator NextChild, map<int, int>::iterator end) :NodeIdx(idx), iter(NextChild), iterend(end)
	{
	}
};

int FindCC(vector<GraphNode>& Graph)
{
	int ccNum = 0;
	stack<infos> st;
	int GraphNodeNum = Graph.size();
	for (int i = 1 ; i < GraphNodeNum; i++)
	{
		if (Graph[i].isVisit == true)
		{
			continue;
		}
		ccNum++;
		Graph[i].isVisit = true;
		st.push(infos(i, Graph[i].Childs.begin(), Graph[i].Childs.end()));

		while (st.size() > 0)
		{
			infos& sn = st.top();
			if (sn.iter == sn.iterend)
			{
				st.pop();
				continue;
			}
			if (!Graph[sn.iter->first].isVisit)
			{
				Graph[sn.iter->first].isVisit = true;
				st.push(infos(sn.iter->first, Graph[sn.iter->first].Childs.begin(), Graph[sn.iter->first].Childs.end()));
			}
			sn.iter++;
		}
	}	
	return ccNum;
}

int main()
{
	int n, e;
	scanf("%d %d", &n, &e);
	int a, b;
	vector<GraphNode> Graph(n + 1);
	for (int i = 0; i < e; ++i)
	{
		scanf("%d %d", &a, &b);
		Graph[a].AddChild(b);
		Graph[b].AddChild(a);
	}

	printf("%d",FindCC(Graph));
	return 0;
}