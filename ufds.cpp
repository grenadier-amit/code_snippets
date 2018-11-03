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
				numsets--;
				int x=find_set(i),y=find_set(j);
				if(rank[x]>rank[y])
				{
					p[y]=x;
					setsize[x]+=setsize[y];
				}
				else
				{
					p[x]=y;
					setsize[y]+=setsize[x];
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

	return 0;
}
