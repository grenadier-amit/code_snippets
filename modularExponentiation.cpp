#include<bits/stdc++.h>
using namespace std;

long long int pow(long long int a,long long int b,long long int mod)
{
	long long int x=1,y=a;

	while(b>0)
	{
		if(b%2==1)
			x=(x*y)%mod;
		y=(y*y)%mod;
		b/=2;
	}

	return x;
}

int main()
{
	return 0;
}