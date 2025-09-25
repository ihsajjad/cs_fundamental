#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
vector<bool> vis;

void dfs(int src)
{
    vis[src] = true;

    cout << src << " ";

    for (int child : adj_list[src])
        if (!vis[child])
            dfs(child);
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

    dfs(1);

    return 0;
}