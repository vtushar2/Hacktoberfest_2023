// Problem Name:- Target Practice
// Problem Link:- https://codeforces.com/contest/1873/problem/C
// Solution:-

#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int t;
    cin >> t;
    while (t--)
    {
        char arr[10][10];
        int ans = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                cin >> arr[i][j];
                if (arr[i][j] == 'X')
                {
                    if (i == 0 && (j >= 0 && j < 10))
                        ans += 1;
                    else if (j == 0 && (i >= 0 && i < 10))
                        ans += 1;
                    else if (i == 9 && (j >= 0 && j < 10))
                        ans += 1;
                    else if (j == 9 && (i >= 0 && i < 10))
                        ans += 1;
                    else if (i == 1 && (j >= 1 && j < 9))
                        ans += 2;
                    else if (j == 1 && (i >= 1 && i < 9))
                        ans += 2;
                    else if (i == 8 && (j >= 1 && j < 9))
                        ans += 2;
                    else if (j == 8 && (i >= 1 && i < 9))
                        ans += 2;
                    else if (i == 2 && (j >= 2 && j < 8))
                        ans += 3;
                    else if (j == 2 && (i >= 2 && i < 8))
                        ans += 3;
                    else if (i == 7 && (j >= 2 && j < 8))
                        ans += 3;
                    else if (j == 7 && (i >= 2 && i < 8))
                        ans += 3;
                    else if (i == 3 && (j >= 3 && j < 7))
                        ans += 4;
                    else if (j == 3 && (i >= 3 && i < 7))
                        ans += 4;
                    else if (i == 6 && (j >= 3 && j < 7))
                        ans += 4;
                    else if (j == 6 && (i >= 3 && i < 7))
                        ans += 4;
                    else if (i == 4 && (j >= 4 && j < 6))
                        ans += 5;
                    else if (j == 4 && (i >= 4 && i < 6))
                        ans += 5;
                    else if (i == 5 && (j >= 4 && j < 6))
                        ans += 5;
                    else if (j == 5 && (i >= 4 && i < 6))
                        ans += 5;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}

