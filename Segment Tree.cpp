#include <iostream>

using namespace std;

const int N=1000;

int arr[N];
int tree[4*N];

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
	build(left,start,mid);
	build(right,mid+1,end);
	tree[node]=tree[left]+tree[right];
}

int query(int node, int start, int end, int i, int j)
{
	if(i>end || j<start)
	{
		return 0;
	}
	if(start>=i && end<=j)
	{
		return tree[node];
	}
	int left=node*2+1;
	int right=node*2+2;
	int mid=(start+end)/2;
	int p1=query(left,start,mid,i,j);
	int p2=query(right,mid+1,end,i,j);
	return p1+p2;
}

void update(int node, int start, int end, int i, int newValue)
{
	if(i<start || i>end)
	{
		return;
	}
	if(start==end)
	{
		tree[node]=newValue;
		return;
	}
	int left=node*2+1;
	int right=node*2+2;
	int mid=(start+end)/2;
	update(left,start,mid,i,newValue);
	update(right,mid+1,end,i,newValue);
	tree[node]=tree[left]+tree[right];
}

int main() {

	int n;
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> arr[i];
	}

	build(0,0,n-1);

	for(int i=0;i<4*n;++i)
	{
		cout << tree[i] << " ";
	}
	cout << endl;

	update(0,0,n-1,2,4);

	cout << query(0,0,n-1,1,3) << endl;

	return 0;
}