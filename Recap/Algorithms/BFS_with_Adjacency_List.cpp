#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;
vector<int> level;
vector<int> parent;

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;

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
                level[child] = level[par] + 1;
                parent[child] = par;
            }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    adj_list.assign(n + 1, vector<int>());
    vis.assign(n + 1, false);
    level.assign(n + 1, 0);
    parent.assign(n + 1, -1);

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