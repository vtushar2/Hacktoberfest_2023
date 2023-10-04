// Problem Name:- Building an Aquarium
// Problem Link:- https://codeforces.com/contest/1873/problem/E
// Solution:-
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
bool check(ll h, ll arr[], ll x, int n)
{
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (h > arr[i])
            ans += h - arr[i];
    }
    if (ans <= x)
        return true;
    return false;
}
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        ll l = 0, r = 1e12;
        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            if (check(mid, arr, x, n))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        if (check(max(l, r), arr, x, n))
            cout << max(l, r) << endl;
        else
            cout << min(l, r) << endl;
    }

    return 0;
}