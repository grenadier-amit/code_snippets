#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector <vii> adjlist;
vi dfs_num,dfs_low,dfs_parent,articulation_vertex;
int dfsRoot,counter,rootChildren;

void bridge(int u)
{
	dfs_low[u]=dfs_num[u]=counter++;
	for(int j=0;j<(int)adjlist[u].size();j++)
	{
		ii v=adjlist[u][j];
		if(dfs_num[v.first]==-1)
		{
			dfs_parent[v.first]=u;
			if(u==dfsRoot)
				rootChildren++;

			bridge(v.first);

			if(dfs_low[v.first]>=dfs_num[u])
				articulation_vertex[u]=1;

			if(dfs_low[v.first]>dfs_num[u])
				printf("Edge (%d %d) is a bridge\n",u,v.first);

			dfs_low[u]=min(dfs_low[u],dfs_low[v.first]);


		}
		else if(v.first!=dfs_parent[u])
		{
			dfs_low[u]=min(dfs_low[u],dfs_num[v.first]);
		}
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
		adjlist[u].push_back(make_pair(v,w));		//UNDIRECTED GRAPH
		adjlist[v].push_back(make_pair(u,w));
	}

	dfs_num.clear();
	dfs_low.clear();
	dfs_parent.clear();
	articulation_vertex.clear();

	counter=0;
	dfs_num.resize(n,-1);
	dfs_low.resize(n,0);
	dfs_parent.resize(n,0);
	articulation_vertex.resize(n,0);

	printf("Bridges:\n");
	for(int i=0;i<n;i++)
	{
		if(dfs_num[i]==-1)
		{
			dfsRoot=i;
			rootChildren=0;
			bridge(i);
			articulation_vertex[dfsRoot]=(rootChildren>1);
		}
	}

	printf("Articulation Points:\n");
	for(int i=0;i<n;i++)
	{
		if(articulation_vertex[i])
			printf("Vertex %d\n",i);
	}

	return 0;
}

