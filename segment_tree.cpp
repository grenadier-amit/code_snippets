#include<bits/stdc++.h>
using namespace std;

void build(int node, int start, int end)
{
    if(start == end)
    {
        // Leaf node will have a single element
        tree[node] = A[start];
    }
    else
    {
        int mid = (start + end) / 2;
        // Recurse on the left child
        build(2*node, start, mid);
        // Recurse on the right child
        build(2*node+1, mid+1, end);
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int idx, int val)
{
    if(start == end)
    {
        // Leaf node
        A[idx] += val;
        tree[node] += val;
    }
    else
    {
        int mid = (start + end) / 2;
        if(start <= idx and idx <= mid)
        {
            // If idx is in the left child, recurse on the left child
            update(2*node, start, mid, idx, val);
        }
        else
        {
            // if idx is in the right child, recurse on the right child
            update(2*node+1, mid+1, end, idx, val);
        }
        // Internal node will have the sum of both of its children
        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val)
{
    // out of range
    if (start > end or start > r or end < l)
        return;

    // Current node is a leaf node
    if (start == end)
    {
        // Add the difference to current node
        tree[node] += val;
        return;
    }

    // If not a leaf node, recur for children.
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);
    updateRange(node*2 + 1, mid + 1, end, l, r, val);

    // Use the result of children calls to update this node
    tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int start, int end, int l, int r)
{
    if(r < start or end < l)
    {
        // range represented by a node is completely outside the given range
        return 0;
    }
    if(l <= start and end <= r)
    {
        // range represented by a node is completely inside the given range
        return tree[node];
    }
    // range represented by a node is partially inside and partially outside the given range
    int mid = (start + end) / 2;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return (p1 + p2);
}

void update_lazy(int seg_tree[],int lazy[],int srange,int erange,int delta,int i,int j,int pos)
{
	if(i>j)
		return;

	if(lazy[pos]!=0)
	{
		seg_tree[pos]+=lazy[pos];
		if(i!=j)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}

	if(srange>j||erange<i)
		return;

	if(srange<=i&&erange>=j)
	{
		seg_tree[pos]+=delta;
		if(i!=j)
		{
			lazy[2*pos+1]+=delta;
			lazy[2*pos+2]+=delta;
		}
		return;
	}

	int mid=(i+j)/2;
	update_lazy(seg_tree,lazy,srange,erange,delta,i,mid,2*pos+1);
	update_lazy(seg_tree,lazy,srange,erange,delta,mid+1,j,2*pos+2);

	seg_tree[pos]=min(seg_tree[2*pos+1],seg_tree[2*pos+2]);

}

int query_lazy(int seg_tree[],int lazy[],int srange,int erange,int i,int j,int pos)
{
	if(i>j)
		return;

	if(lazy[pos]!=0)
	{
		seg_tree[pos]+=lazy[pos];
		if(i!=j)
		{
			lazy[2*pos+1]+=lazy[pos];
			lazy[2*pos+2]+=lazy[pos];
		}
		lazy[pos]=0;
	}

	if(srange>j||erange<i)
		return 1000000007;

	if(srange<=i&&erange>=j)
		return seg_tree[pos];

	int mid=(i+j)/2;
	
	return min(query_lazy(seg_tree,lazy,srange,erange,i,mid,2*pos+1),query_lazy(seg_tree,lazy,srange,erange,mid+1,j,2*pos+2));

}

int main()
{

	return 0;
}
