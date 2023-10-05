// Problem Name:- Good Kit
// Problem Link:- https://codeforces.com/contest/1873/problem/B
// Solution:-

#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        arr[0]++;
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            ans *= arr[i];
        }
        cout << ans << endl;
    }

    return 0;
}