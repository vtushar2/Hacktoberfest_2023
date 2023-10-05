// Problem Name:- Mad City
// Problem Link:- https://codeforces.com/contest/1873/problem/H
// Solution:-

#include <bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[], vector<int> &vis, stack<int> &st, int node, int par)
{
    vis[node] = 1;
    st.push(node);
    for (auto x : adj[node])
    {
        if (vis[x] == 0)
        {
            if (dfs(adj, vis, st, x, node))
                return true;
        }
        else if (x != par)
        {
            st.push(x);
            return true;
        }
    }
    st.pop();
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> adj[n + 1];
        for (int i = 0; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        set<int> s;
        vector<int> pathvis(n + 1, 0);
        vector<int> vis(n + 1, 0);
        stack<int> st;
        dfs(adj, vis, st, 1, -1);
        int last = st.top();
        s.insert(last);
        st.pop();
        while (st.top() != last)
        {
            s.insert(st.top());
            st.pop();
        }

        queue<pair<int, int>> q;
        q.push({b, 0});
        int ta = 0, an = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int time = it.second;
            if (s.find(node) != s.end())
            {
                ta = time;
                an = node;
                break;
            }
            for (auto x : adj[node])
            {
                if (pathvis[x] == 0)
                    q.push({x, time + 1});
                pathvis[x] = 1;
            }
        }
        while (!q.empty())
        {
            q.pop();
        }

        for (int i = 0; i <= n; i++)
            pathvis[i] = 0;
        q.push({a, 0});
        pathvis[a] = 1;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int node = it.first;
            int time = it.second;
            if (node == an)
            {
                if (time <= ta)
                    cout << "NO" << endl;
                else
                    cout << "YES" << endl;
                break;
            }
            for (auto x : adj[node])
            {
                if (pathvis[x] == 0)
                    q.push({x, time + 1});
                pathvis[x] = 1;
            }
        }
    }

    return 0;
}