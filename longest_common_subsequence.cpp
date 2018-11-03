#include<bits/stdc++.h>
using namespace std;

int dp(char s1[],char s2[])
{
	int n=strlen(s1),m=strlen(s2);
	int ans[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0)
				ans[i][j]=0;
			else if(s1[i]==s2[j])
				ans[i][j]=ans[i-1][j-1]+1;
			else
				ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
			}
	}
	return ans[n][m];
}

int main()
{

return 0;
}
