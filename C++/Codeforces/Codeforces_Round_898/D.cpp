// Problem Name:- 1D-Eraser
// Problem Link:- https://codeforces.com/contest/1873/problem/D
// Solution:-
#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int i = 0;
        int ans = 0;
        while (i < s.length())
        {
            if (s[i] == 'B')
            {
                i += k;
                ans++;
            }
            else
                i++;
        }
        cout << ans << endl;
    }

    return 0;
}