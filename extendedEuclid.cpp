#include<bits/stdc++.h>
using namespace std;

pair<int,pair<int,int> > extendedEuclid(int a,int b)
{
	if(a==0)
		return make_pair(b,make_pair(0,1));
	pair<int,pair<int,int> > p;
	p=extendedEuclid(b%a,a);
	return make_pair(p.first,make_pair(p.second.second-p.second.first*(b/a),p.second.first));
}

int modInverse(int a,int m)
{
	return (extendedEuclid(a,m).second.first+m)%m;
}

int main()
{
	int a,m,ans;
	scanf("%d %d",&a,&m);
	ans=modInverse(a,m);
	printf("%d\n",ans);
	return 0;
}