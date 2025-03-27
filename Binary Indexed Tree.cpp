#include <iostream>
#include <vector>

#define N 100000
#define mx 1000
#define ll long long

using namespace std;

int arr[mx];
int tree[mx];

int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void update(int idx, int val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 1;i <= n; ++i)
    {
        cin >> arr[i];
        update(i, arr[i], n);
    }
    cout << query(10) << endl;
    return 0;
}