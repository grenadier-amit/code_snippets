#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

class union_find
{
	private:
		vi p,rank,setsize;
		int numsets;
	public:
		union_find(int n)
		{
			setsize.assign(n,1);
			numsets=n;
			rank.assign(n,0);
			p.assign(n,0);
			for(int i=0;i<n;i++)
				p[i]=i;
		}
		int find_set(int i)
		{
			return (p[i]==i) ? i : (p[i]=find_set(p[i]));
		}
		bool is_same_set(int i,int j)
		{
			return find_set(i)==find_set(j);
		}
		void union_set(int i,int j)
		{
			if(!is_same_set(i,j))
			{
				int x=find_set(i),y=find_set(j);
				if(rank[x]>rank[y])
					p[y]=x;
				else
				{
					p[x]=y;
					if(rank[x]==rank[y])
						rank[y]++;
				}
			}
		}
		int num_dis_sets()
		{
			return numsets;
		}
		int sizeofsets(int i)
		{
			return setsize[find_set(i)];
		}
};

int main()
{
	int v,e;
	vector< pair<int,ii> > edgelist;
	printf("enter no of vertices and edges respectively\n");
	scanf("%d %d",&v,&e);
	int x,y,w;
	for(int i=0;i<e;i++)
	{
		scanf("%d %d %d",&x,&y,&w);
		edgelist.push_back(make_pair(w,make_pair(x,y)));
	}
	sort(edgelist.begin(),edgelist.end());

	int mst_cost=0;
	union_find uf(v);
	for(int i=0;i<e;i++)
	{
		pair<int,ii> front=edgelist[i];
		if(!uf.is_same_set(front.second.first,front.second.second))
		{
			mst_cost+=front.first;
			uf.union_set(front.second.first,front.second.second);
		}
	}
	printf("mst cost is %d\n",mst_cost);
	return 0;
}
