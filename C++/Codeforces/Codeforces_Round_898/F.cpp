// Problem Name:- Money Trees
// Problem Link:- https://codeforces.com/contest/1873/problem/F
// Solution:-
#include <bits/stdc++.h>
using namespace std;
int check(int a[], int l, int r, int k)
{
    int sum = 0;
    int ans = 0;
    int start = l, end = l;

    while (end <= r)
    {
        sum += a[end];
        if (sum <= k)
        {
            ans = max(ans, end - start + 1);
        }
        else
        {
            while (sum > k)
            {
                sum -= a[start];
                start++;
            }
        }
        end++;
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int a[n], h[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int ans = 0;
        int last = h[0];
        int l = 0, r = 0;
        int i = 0;
        while (i < n)
        {
            if (last % h[i] == 0)
            {
                last = h[i];
                i++;
            }
            else
            {

                ans = max(ans, check(a, l, i - 1, k));
                l = i;
                r = i;
                last = h[i];
            }
        }

        ans = max(ans, check(a, l, i - 1, k));
        cout << ans << endl;
    }

    return 0;
}
