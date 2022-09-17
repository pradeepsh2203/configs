#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll bin_pow(ll num, ll a, ll mod)
{
    ll res = 1;
    num = num % mod;

    while (a != 0)
    {
        if (a & 1)
        {
            res = (res * num) % mod;
        }
        num = (num * num) % mod;
        a = a >> 1;
    }

    return num;
}
