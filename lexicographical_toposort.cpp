#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > adj;
vector<int> indegree;
vector<int> ts;
void toposort(int n)
{
	set<int> minheap;
	for(int i=1;i<=n;i++)
	{
		if(indegree[i]==0)
			minheap.insert(i);
	}
	int a,b;
	while(!minheap.empty())
	{
		a=(*minheap.begin());
		minheap.erase(minheap.begin());
		ts.push_back(a);
		for(int i=0;i<adj[a].size();i++)
		{
			b=adj[a][i];
			indegree[b]--;
			if(indegree[b]==0)
				minheap.insert(b);
		}
	}
}

int main()
{
	return 0;
}