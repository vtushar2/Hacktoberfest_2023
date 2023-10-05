// Problem Name:- ABBC or BACB
// Problem Link:- https://codeforces.com/contest/1873/problem/G
// Solution:-
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int ans = 0;
        bool flag = false;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'A')
                ans++;
        }
        if (s[0] == 'B' || s[n - 1] == 'B')
            cout << ans << endl;
        else
        {
            int rm = 1e6;
            int count = 0;
            for (int i = 0; i < n; i++)
            {
                if (s[i] == 'A')
                    count++;
                else
                {
                    rm = min(rm, count);
                    count = 0;
                }
            }
            rm = min(rm, count);
            cout << ans - rm << endl;
        }
    }

    return 0;
}
