#include <iostream>

using namespace std;

const int N = 100000;

int arr[N];

int tree[4*N];

void build(int n, int b, int e)
{
	if(b == e)
	{
		tree[n] = arr[b];
		return;
	}
	int l = 2*n;
	int r = 2*n + 1;
	int mid = (b + e) / 2;

	build(l, b, mid);
	build(r, mid+1, e);

	tree[n] = tree[l] + tree[r];
}

void update(int n, int b, int e, int i, int x)
{
	if(i<b || e<i)
	{
		return;
	}
	if(b == e && b == i)
	{
		tree[n] = x;
		return;
	}
	int l = 2*n;
	int r = 2*n + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, x);
	update(r, mid+1, e, i, x);

	tree[n] = tree[l] + tree[r];
}

int query(int n, int b, int e, int i, int j)
{
	if(b > j || e < i)
	{
		return 0;
	}
	if(b >= i && e <= j)
	{
		return tree[n];
	}
	int l = 2*n;
	int r = 2*n + 1;
	int mid = (b + e) / 2;

	int L = query(l, b, mid, i, j);
	int R = query(r, mid+1, e, i, j);

	return L + R;
}

int32_t main() {
	int n, q;
	cin >> n >> q;
	for(int i=1;i<=n;++i)
	{
		cin >> arr[i];
	}

	build(1, 1, n);

	cout << tree[1] << endl;

	for(int i=1; i<=2*n; ++i)
	{
		cout << tree[i] << " ";
	}

  return 0;
}
