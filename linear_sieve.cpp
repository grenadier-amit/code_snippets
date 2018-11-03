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



int main()
{
	const int N = 10000000 ;
	int lp [ N + 1 ] ;
	vector < int > pr ;

	for ( int i = 2 ; i <= N ; ++ i ) 
	{
		if ( lp [ i ] == 0 ) 
		{
			lp [ i ] = i ;
			pr. push_back ( i ) ;
		}
		for ( int j = 0 ; j < ( int ) pr. size ( ) && pr [ j ] <= lp [ i ] && i * pr [ j ] <= N ; ++ j )
			lp [ i * pr [ j ] ] = pr [ j ] ;
	} 
	return 0;
}
