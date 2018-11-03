#include<bits/stdc++.h>
using namespace std;
long long int  pow(long long int a,long long  int b,long long  int MOD)
{
    long long int x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD) x%=MOD;
        }
        y = (y*y);
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}
long long int InverseEuler(long long int n,long long  int MOD)
{
    return pow(n,MOD-2,MOD);
}
long long int com1(long long int  n,long long  int r,long long  int MOD)
{
long long int i;
    vector<long long int> f(n + 1,1);
    for ( i=2; i<=n;i++)
        f[i]= (f[i-1]*i) % MOD;
    return (f[n]*((InverseEuler(f[r], MOD) * InverseEuler(f[n-r], MOD)) % MOD)) % MOD;
}
long long int  Lucas(long long int n,long long int m,long long  int p)
{
    if (n==0 && m==0) return 1;
   long long  int ni = n % p;
   long long  int mi = m % p;
    if (mi>ni) return 0;
    return Lucas(n/p, m/p, p) * com1(ni, mi, p);
}
long long int com(long long int n,long long int r,long long int MOD)
{
    return Lucas(n, r, MOD);
}

int main()
{
    return 0;
}