#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;

int main()
{

	int n,e,i,j;
	printf("enter no of vertices and no of edges respectively\n");
	scanf("%d %d",&n,&e);

	vector<vii> adjlist(n); //adjacency list
	for(i=0;i<e;i++)
	{
		int u,v,w;
		scanf("%d %d %d",&u,&v,&w);
		adjlist[u].push_back(make_pair(v,w));
	}

	for(i=0;i<n;i++)
	{
		printf("%d\t",i);
		for(j=0;j<adjlist[i].size();++j)
			printf("%d %d\t",adjlist[i][j].first,adjlist[i][j].second);
		printf("\n");
	}

	return 0;
}
