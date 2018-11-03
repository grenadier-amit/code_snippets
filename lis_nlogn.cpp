#include<bits/stdc++.h>
using namespace std;

vector<int> arr,temp,ans;
int n,len;

int bsearch(int i,int j,int value)
{
	while(i<j)
	{
		int mid=(i+j)/2;
		if(value>arr[temp[mid]])
		{
			i=mid+1;
		}
		else
		{
			j=mid;
		}
	}
	return j;
}

void lis()
{
	temp.push_back(0);
	len++;
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[temp[len]])
		{
			temp.push_back(i);
			len++;
			ans[i]=temp[len-1];
		}
		else if(arr[i]<=arr[temp[0]])
		{
			temp[0]=i;
		}
		else
		{
			int index=bsearch(0,len,arr[i]);
			temp[index]=i;
			ans[i]=temp[index-1];
		}
	}
}

int main()
{
	scanf("%d",&n);
	arr.clear();
	temp.clear();
	ans.clear();
	arr.resize(n);
	ans.resize(n,-1);
	len=-1;
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	lis();
	printf("lis length = %d\n",len+1);
	int x=temp[len];
	while(x!=-1)
	{
		printf("%d ",arr[x]);
		x=ans[x];
	}
	printf("\n");
	return 0;
}