#include<bits/stdc++.h>
using namespace std;

int modulo(int a,int b,int c)
{
	long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
	while(b > 0)
	{
		if(b%2 == 1)
		{
			x=(x*y)%c;
		}
		y = (y*y)%c; // squaring the base
		b /= 2;
	}
	return x%c;
}

int main()
{

	return 0;
}
