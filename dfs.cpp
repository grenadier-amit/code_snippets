#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vi dfs_num;
vector<vii> adjlist;

void dfs(int u)
{

	dfs_num[u]=1;

	for(int j=0;j<(int)adjlist[u].size();j++)
	{
		if(dfs_num[adjlist[u][j].first]==-1)
		{
			printf("->%d",adjlist[u][j].first);
			dfs(adjlist[u][j].first);
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
		adjlist[u].push_back(make_pair(v,w));
	}

	while(1)
	{
		printf("enter vertex to start dfs\n");
		int temp;
		scanf("%d",&temp);

		if(temp==-1)
		break;

		dfs_num.clear();
		dfs_num.resize(n,-1);
		printf("%d",temp);
		dfs(temp);
		for(i=0;i<n;i++)
		{
			if(dfs_num[i]==-1)
			{
				printf("->%d",i);
				dfs(i);
			}
		}
		printf("\n");
	}

	return 0;
}

