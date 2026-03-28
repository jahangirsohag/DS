#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cstring>
#include <cstdint>
#include <functional>

using namespace std;

vector<long long> tree(2*1e5, 0);

void update(int idx, int val, int n)
{
	while(idx <= n)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

long long query(int idx)
{
	long long sum = 0;

	while(idx > 0)
	{
		sum += tree[idx];
		idx -= (idx & -idx);
	}

	return sum;
}

int32_t main()
{
	int n, q;
	cin >> n >> q;
	int arr[n + 1];
	for(int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		update(i, arr[i], n);
	}
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		cout << query(b) - query(a - 1) << endl;
	}

	return 0;
}