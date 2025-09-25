#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;

    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        cout << par << " ";

        for (int child : adj_list[par])
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    adj_list.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);

    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    bfs(1);

    return 0;
}