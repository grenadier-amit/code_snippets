#include<bits/stdc++.h>
using namespace std;

int knapsack(int val[],int w[],int n,int wt)
{
	if(n==0||wt==0)
		return 0;

	if(w[n-1]>wt)
		return knapsack(val,w,n-1,wt);
	else
		return max(val[n-1]+knapsack(val,w,n-1,wt-w[n-1]),knapsack(val,w,n-1,wt));
}

int knapsack_top_down(int val[],int w[],int n,int wt)
{
	int** mem=new int*[n];
	int
	int ans=knapsack(val,w,n,wt);
}

int main()
{

	return 0;
}
