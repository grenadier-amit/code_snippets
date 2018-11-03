#include<bits/stdc++.h>
using namespace std;

int *m,n;

int matrix_dp()
{
	int **mul;
	mul=new int*[n];
	for(int i=0;i<n;i++)
		mul[i]=new int[n];
	for(int l=2;l<n;l++)
	{
		for(int i=1;i<=n-l+1;i++)
		{
			int j=i+l-1;
			for(int k=i;k<=j-1;k++)
			{

			}
		}
	}
}

int main()
{
	scanf("%d",&n);
	m=new int[n+1];
	for(int i=0;i<=n;i++)
		scanf("%d",&m[i]);
	int ans=matrix_dp();
	printf("%d\n",ans);
	delete[] m;
	return 0;
}
