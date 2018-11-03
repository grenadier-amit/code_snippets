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

int factmod ( int n, int p ) 
{
	int res = 1 ;
	while ( n > 1 ) 
	{
		res = ( res * ( ( n / p ) % 2 ? p - 1 : 1 ) ) % p ;
		for ( int i = 2 ; i <= n % p ; ++ i )
			res = ( res * i ) % p ;
		n / = p ;
	}
	return res % p ;
}

int main()
{

	return 0;
}
