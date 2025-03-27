#include <iostream>
#include <vector>

#define N 100000
#define mx 1000
#define ll long long

using namespace std;

int arr[mx];
int pref[mx];
int tree[mx];

void prefSum(int arr[], int n)
{
    pref[1] = arr[1];
    for(int i = 2; i <= n; ++i)
    {
        pref[i] = pref[i-1] + arr[i];
    }
}

void update(int idx, int val, int n)
{
    while(idx <= n)
    {
        tree[idx] += val;
        idx += (idx & -idx); // idx += idx & (~idx + 1);
    }
}

int query(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= (idx & -idx); // idx = idx & (idx - 1);
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> arr[i];

        update(i, arr[i], n);

    }

    cout << "Index: ";

    for(int i = 1; i <= n; ++i)
    {
        cout << i << " ";
    }
    cout << endl;


    cout << "Array: ";
    for(int i = 1; i <= n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    prefSum(arr, n);

    cout << "PrefS: ";
    for(int i = 1; i <= n; ++i)
    {
        cout << pref[i] << " ";
    }

    cout << "Tree : ";
    for(int i = 1; i <= n; ++i)
    {
        cout << tree[i] << " ";
    }
    cout << endl;

    cout << "Query Sum : ";
    cout << query(10) << endl; 



    return 0;
}