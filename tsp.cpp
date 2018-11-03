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

#define inf 1000000007
#define CITY 13

int vis[CITY][1 << CITY]={0}; // is_visited
int val[CITY][1 << CITY]={0}; // cost at particular state
int weight[CITY][CITY],n; // given weight
 
int dp (int at, int mask)
{
    if ( mask ==  (1 << n) - 1 ) 
    { // all visited
        vis[at][mask] = 1;
        return val[at][mask]+weight[at][0];
    }
 
    if ( vis[at][mask] ) 
        return val[at][mask];
   
    vis[at][mask] = 1;
 
    int ans = inf;
    int cost,nxt;
 
    for (nxt = 0; nxt < n; nxt++ ) 
    {
        if ( nxt!=at && (mask & (1 << nxt)) == 0 ) {
            cost = dp (nxt, mask | (1 << nxt)) + weight[at][nxt];
            if ( ans > cost ) ans = cost;
        }
    }
 
    return val[at][mask] = ans;
}

int main()
{
	int ans=dp(0,1);
	return 0;
}
