// Problem Name - Short Short
// Problem Link - https://codeforces.com/contest/1873/problem/A
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
        int count = 0;
        for (int i = 0; i < 3; i++)
        {
            if (s[i] != ('a' + i))
                count++;
        }
        if (count > 2)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}
