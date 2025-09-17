#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
vector<int> nodes;

void bfs(int src, int l)
{
    queue<pair<int, int>> q;
    q.push({src, 0});
    vis[src] = true;

    while (!q.empty())
    {
        auto itm = q.front();
        q.pop();

        int par = itm.first;
        int level = itm.second;

        if (level == l)
            nodes.push_back(par);

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push({child, level + 1});
                vis[child] = true;
            }
        }
    }
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
    int l;
    cin >> l;

    bfs(0, l);

    sort(nodes.begin(), nodes.end(), greater<int>());

    for (int node : nodes)
        cout << node << " ";

    return 0;
}