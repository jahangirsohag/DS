#include <iostream>

using namespace std;

const int N = 100000;

struct ST {
	long long sum;
	long long prop;
} tree[4*N];

void build(int n, int b, int e)
{
	if(b == e)
	{
		tree[n].sum = 0;
		return;
	}

	int l = 2*n;
	int r = 2*n + 1;
	int mid = (b + e) / 2;

	build(l, b, mid);
	build(r, mid+1, e);

	tree[n].sum = tree[l].sum + tree[r].sum;
	tree[n].prop = 0;
}

void update(int n, int b, int e, int i, int j, long long x)
{
	if(i > e || j < b)
	{
		return;
	}
	if(b >=i && e <= j)
	{
		tree[n].sum += (e - b + 1) * x;
		tree[n].prop += x;
		return;
	}

	int l = 2*n;
	int r = 2*n + 1;
	int mid = (b + e) / 2;

	update(l, b, mid, i, j, x);
	update(r, mid+1, e, i, j, x);

	tree[n].sum = tree[l].sum + tree[r].sum + (e - b + 1) * tree[n].prop;
}

long long query(int n, int b, int e, int i, int j, long long carry = 0)
{
	if(i > e || j < b)
	{
		return 0;
	}
	if(b >= i && e <= j)
	{
		return tree[n].sum + carry * (e - b + 1);
	}

	int l = 2*n;
	int r = 2*n + 1;
	int mid = (b + e) / 2;

	long long p1 = query(l, b, mid, i, j, carry + tree[n].prop);
	long long p2 = query(r, mid+1, e, i, j, carry + tree[n].prop);

	return p1 + p2;
}

int main() {
	int n, m;
	cin >> n >> m;

	build(1, 1, n);

	while(m--)
	{
		int op;
		cin >> op;
		if(op == 1)
		{
			int i, j, x;
			cin >> i >> j >> x;
			update(1, 1, n, i+1, j, x);
		}
		else
		{
			int i, j;
			cin >> i >> j;
			cout << query(1, 1, n, i+1, j) << endl;
		}
	}
	return 0;
}
