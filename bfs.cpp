#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
vector <vii> adjlist;

queue<int> q;
vi d;

void bfs(int s)
{
	d[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front();
		printf("%d->",u);
		q.pop();
		for(int j=0;j<(int)adjlist[u].size();j++)
		{
			ii v=adjlist[u][j];
			if(d[v.first]==INF)
			{
				d[v.first]=d[u]+1;
				q.push(v.first);
			}
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
		int x;
		printf("enter vertex to start bfs\n");
		scanf("%d",&x);
		if(x==-1)
			break;
		d.clear();
		d.resize(n,INF);
		bfs(x);
		printf("\n");
	}

	return 0;
}
