#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a;i<=b;i++)
#define rep1(i,a,b) for(int i=a;i<b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
#define per1(i,a,b) for(int i=a;i>b;i--)

#define sci1(x) scanf("%d",&x);
#define sci2(x,y) scanf("%d %d",&x,&y);
#define sci3(x,y,z) scanf("%d %d %d",&x,&y,&z);

#define scl1(x) scanf("%lld",&x);
#define scl2(x,y) scanf("%lld %lld",&x,&y);
#define scl3(x,y,z) scanf("%lld %lld %lld",&x,&y,&z);

#define mp make_pair
#define pb push_back

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef set<int>::iterator sit;
typedef vector<int>::iterator vit;
typedef map<int,int>::iterator mit;
/*#################### AMIT KUMAR YADAV ## MNNIT ALLAHABAD ####################*/

int preProcess[10003][15];

template<class T>
class RMQMin
{
	T *A;
	public:
	RMQMin(int N,T *array):A(array)
	{
		int i,j;
		for (i=0;i<N;i++)
			preProcess[i][0]=i;
		for (j=1; (1<<j)<=N; j++)
		{
			for (i=0; i+(1<<j)-1<N; i++)
			{
				preProcess[i][j]=
				A[preProcess[i][j-1]]<=
				A[preProcess[i+(1<<(j-1))][j-1]]?
				preProcess[i][j-1]
				:preProcess[i+(1<<(j-1))][j-1];
			}
		}
	}

	int query(int start,int end)
	{
		int diff=end-start;
		diff=31 - __builtin_clz(diff+1);
		return A[preProcess[start][diff]]
			<=A[preProcess[end-(1<<diff)+1][diff]]?
			preProcess[start][diff]
			:preProcess[end-(1<<diff)+1][diff];
	}
};

int main()
{

	return 0;
}
