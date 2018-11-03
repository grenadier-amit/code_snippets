#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <vii> adjlist;
vi ts,dfs_num;

void topo_sort(int u)
{
	dfs_num[u]=1;
	for(int j=0;j<(int)adjlist[u].size();j++)
	{
		ii v=adjlist[u][j];
		if(dfs_num[v.first]==-1)
		{
			topo_sort(v.first);
		}
	}
	ts.push_back(u);
}

int main()
{
	int n,e,i,j;
	printf("enter no of vertices and no of edges respectively\n");
	scanf("%d %d",&n,&e);

	adjlist.resize(n);

	for(i=0;i<e;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adjlist[u].push_back(make_pair(v,w));
	}

	ts.clear();
	dfs_num.clear();
	dfs_num.resize(n,-1);
	for(int i=0;i<n;i++)
	{
		if(dfs_num[i]==-1)
			topo_sort(i);
	}
	for(int i=(int)ts.size()-1;i>=0;i--)
		printf("%d->",ts[i]);
	printf("\n");

	return 0;
}
