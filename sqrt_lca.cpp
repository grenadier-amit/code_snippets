#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define per1(i,a,b) for(int i=a;i>b;i--)

#define sci1(x) scanf("%d",&x);
#define sci2(x,y) scanf("%d %d",&x,&y);
#define sci3(x,y,z) scanf("%d %d %d",&x,&Y,&z);

#define scl1(x) scanf("%lld",&x);
#define scl2(x,y) scanf("%lld %lld",&x,&y);
#define scl3(x,y,z) scanf("%lld %lld %lld",&x,&Y,&z);

#define mp make_pair
#define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> vii;



vector<vi> tree;

void traverse(int node,int head,int prev,int parent[],int level[],int ancestor[])
{
	int curr=sqrt(level[node]+1);
	if(curr==1)
	{
		ancestor[node]=1;
	}
	else
	{
		if(curr==prev+1)
		{
			ancestor[node]=parent[node];
			head=node;
		}
		else
		{
			ancestor[node]=parent[head];
		}
	}

	rep1(i,0,tree[node].size())
	{
		if(tree[node][i]!=parent[node])
		{
			traverse(tree[node][i],head,curr,parent,level,ancestor);
		}
	}
}

int lca(int u,int v)
{
	while(ancestor[u]!=ancestor[v])
	{
		if(level[u]>level[v])
		{
			u=ancestor[u];
		}
		else
		{
			v=ancestor[v];
		}
	}

	while(u!=v)
	{
		if(level[u]>level[v])
		{
			u=parent[u];
		}
		else
		{
			v=parent[v];
		}
	}
	return u;
}

int main()
{

	return 0;
}
