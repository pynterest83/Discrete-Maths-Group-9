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
int EulerEx(int a, int b, int &x, int &y)
{
    if (!a)
    {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int ret = EulerEx(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return ret;
}

main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, x, y;
    cin >> a >> b;
    if (EulerEx(a, b, x, y) == 1)
    {
        while (x < 0) x += b;
        cout << x << " la nghich dao cua " << a << " theo modulo " << b;
    }
    else
    {
        cout << "Khong ton tai nghich dao modulo cua " << a << " theo modulo " << b;
    };
    return 0;
}
