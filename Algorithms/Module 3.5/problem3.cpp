// Question: You will be given an undirected graph as input. You need to tell the number of nodes in each component in ascending order.

#include <bits/stdc++.h>
using namespace std;

vector<int> adj_list[1005];
bool vis[1005];

int dfs(int src)
{
    int count = 0;
    vis[src] = true;
    for (int child : adj_list[src])
    {
        if (!vis[child])
            count += dfs(child);
    }

    return count + 1;
}

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    memset(vis, false, sizeof(vis));

    vector<int> nodes;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int val = dfs(i);
            nodes.push_back(val);
        }
    }

    sort(nodes.begin(), nodes.end());

    for (int node : nodes)
        cout << node << " ";

    return 0;
}