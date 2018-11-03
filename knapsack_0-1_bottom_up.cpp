#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int wt[],int w,int n)
{
	int dp[n+1][w+1];

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(i==0||j==0)
				dp[i][j]=0;
			else if(j<wt[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=max(dp[i-1][j-wt[i]]+val[i],dp[i-1][j]);
		}
	}
}

int main()
{

return 0;
}
