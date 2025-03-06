#include <iostream>

using namespace std;

const int N=3e5+9;

long long arr[N];
long long tree[4*N];

void build(int node, int start, int end)
{
	if(start==end)
	{
		tree[node]=arr[start];
		return;
	}
	int left=node*2+1;
	int right=node*2+2;
	int mid=(start+end)/2;
	build(left, start, mid);
	build(right, mid+1, end);
	tree[node]=tree[left]+tree[right];
}

void update(int node, int start, int end, int i, int v)
{
	if(i<start || i>end)
	{
		return;
	}
	if(start==end)
	{
		tree[node]=v;
		arr[i]=v;
		return;
	}
	int left=node*2+1;
	int right=node*2+2;
	int mid=(start + end)/ 2;
	update(left, start, mid, i, v);
	update(right, mid+1, end, i, v);
	tree[node]=tree[left]+tree[right];
}

long long query(int node, int start, int end, int i, int j)
{
	if(i>end || j<start)
	{
		return 0;
	}
	if(start>=i && end<=j)
	{
		return tree[node];
	}
	int left=node*2 + 1;
	int right=node*2 + 2;
	int mid=(start + end)/2;
	long long p1=query(left, start, mid, i, j);
	long long p2=query(right, mid+1, end, i, j);
	return p1 + p2;
}

int main() {
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;++i)
	{
		cin >> arr[i];
	}
	build(0,0,n-1);
	while(m--)
	{
		int op;
		cin >> op;
		if(op==1)
		{
			int i,v;
			cin >> i >> v;
			update(0,0,n-1,i,v);
		}
		else
		{
			int i,j;
			cin >> i >> j;
			cout << query(0,0,n-1,i,j-1) << endl;
		}
	}
	return 0;
}