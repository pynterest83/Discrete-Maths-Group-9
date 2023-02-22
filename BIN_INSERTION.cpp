#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define FORU(i , a , b) for(int i = a ; i <= b ; i++)
#define FORD(i , a , b) for(int i = a ; i >= b ; i--)
using namespace std;
const int MAX = 1e6 + 10, MOD = 1e9 + 7;
void unset(int &t, int pos)
{
    t &= (~(1ll << (pos - 1)));
}
void onset(int &t, int pos)
{
    t |= (1ll << (pos - 1));
}
int getbit(int i,int k)
{
    return (k >> (i - 1)) % 2;
}
void minimize(int &x, int y)
{
    x = min(x, y);
}
void maximize(int &x, int y)
{
    x = max(x, y);
}
int ADD(int x, int y)
{
    return (x + y) % MOD;
}
int MINUS(int x, int y)
{
    x %= MOD, y %= MOD;
    if (x < y) x += MOD;
    return (x - y) % MOD;
}
//========================================================================0========================================================================//
int a[MAX], n, res[MAX];
int bin_search(int _r, int val)
{
    int l = 1, r = _r, mid, ret = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        if (val >= res[mid])
        {
            l = mid + 1;
            ret = mid;
        }
        else r = mid - 1;
    }
    return ret + 1;
}
void insertion(int pos, int r, int val)
{
    for (int i = r + 1; i > pos; i--) res[i] = res[i - 1];
    res[pos] = val;
}
void solve()
{
    res[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        int pos = bin_search(i - 1, a[i]);
        insertion(pos, i - 1, a[i]);
    }
    for (int i = 1; i <= n; i++) cout << res[i] << " ";
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("t.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    solve();
    return 0;
}
