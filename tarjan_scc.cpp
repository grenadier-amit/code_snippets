#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <vii> adjlist;
vi dfs_num,dfs_low,s,visited;
int counter,num;

void tarjan_scc(int u)
{
	dfs_low[u]=dfs_num[u]=counter++;
	s.push_back(u);
	visited[u]=1;
	for(int j=0;j<(int)adjlist[u].size();j++)
	{
		ii v=adjlist[u][j];
		if(dfs_num[v.first]==-1)
			tarjan_scc(v.first);
		if(visited[v.first])
			dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);
	}
	if(dfs_low[u]==dfs_num[u])
	{
		printf("SCC %d: ",++num);
		while(1)
		{
			int v=s.back();
			s.pop_back();
			visited[v]=0;
			printf(" %d",v);
			if(u==v)
				break;
		}
		printf("\n");
	}
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
                adjlist[u].push_back(make_pair(v,w));           //DIRECTED GRAPH
        }

	dfs_num.clear();
	dfs_low.clear();
	visited.clear();

	dfs_num.resize(n,-1);
	dfs_low.resize(n,0);
	visited.resize(n,0);
	counter=0;
	num=0;

	for(int i=0;i<n;i++)
	{
		if(dfs_num[i]==-1)
			tarjan_scc(i);
	}

	return 0;
}
