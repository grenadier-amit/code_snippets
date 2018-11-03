#include<bits/stdc++.h>
using namespace std;
int n;
int arr[]={23,45,12,3,4};
int arr2[]={2,4,1,9,4,4,4,6,12,34,23,2,4};
void max_heapify(int i)
{
	int left=2*i+1;
	int right=2*i+2;
	int largest;
	if(left<n&&arr[left]>arr[i])
		largest=left;
	else
		largest=i;
	if(right<n&&arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		swap(arr[i],arr[largest]);
		max_heapify(largest);
	}
}

void min_heapify(int i)
{
	int left=2*i;
	int right=2*i+1;
	int smallest;
	if(left<=n&&arr[left]<arr[i])
		smallest=left;
	else
		smallest=i;
	if(right<=n&&arr[right]<arr[smallest])
		smallest=right;
	if(smallest!=i)
	{
		swap(arr[i],arr[smallest]);
		max_heapify(smallest);
	}
}

void build_maxheap()
{
	int x=floor(n/2.0);
	for(int i=x;i>=0;i--)
	{
		max_heapify(i);
	}
}

void build_minheap()
{
	for(int i=floor(n/2.0);i>=1;i--)
	{
		min_heapify(i);
	}
}

int find_maxheap_element(int i,int x)
{
	if(arr[i]==x)
		return i;
	int left=0,right=0;
	if(2*i<=n)
		left=find_maxheap_element(2*i,x);
	if(2*i+1<=n)
		right=find_maxheap_element(2*i+1,x);
	if(left)
		return left;
	else if(right)
		return right;
	else
		return 0;
}

int extract_max()
{
	if(n<=0)
		return -1;
	int maxi=arr[0];
	if(n-1>=0)
	{
		arr[0]=arr[n-1];
		n--;
		max_heapify(0);
	}
	else
		n--;
	return maxi;
}

int main()
{
	n=sizeof(arr)/sizeof(arr[0]);
	int nn=n;
	build_maxheap();
	for(int i=0;i<nn;i++)
	{
		printf("%d ",extract_max());
	}
	printf("\n");
	return 0;
}