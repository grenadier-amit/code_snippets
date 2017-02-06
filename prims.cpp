#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vi taken;
priority_queue<ii,vector<ii>,greater<ii> > pq;
vector<vii> adjlist;
int n,e,mst_count;

void prims(int u)
{
	taken[u]=1;
	for(int i=0;i<adjlist[u].size();i++)
	{
		ii v=adjlist[u][i];
		if(!taken[v.first])
			pq.push(make_pair(v.second,v.first));
	}
}

int main()
{
	scanf("%d %d",&n,&e);
	adjlist.clear();
	adjlist.resize(n);
	taken.assign(n,0);
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adjlist[u].push_back(make_pair(v,w));
		adjlist[v].push_back(make_pair(u,w));
	}
	mst_count=0;
	prims(0);
	while(!pq.empty())
	{
		ii front=pq.top();
		pq.pop();
		int a=front.first,b=front.second;
		if(!taken[b])
		{
			mst_count+=a;
			prims(b);
		}
	}
	printf("MST count is %d\n",mst_count);
	return 0;
}
