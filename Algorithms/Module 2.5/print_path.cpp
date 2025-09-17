#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj_list;
bool vis[100001];
int parent[100001];

void bfs(int src, int n)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                parent[child] = par;
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
    memset(parent, -1, sizeof(parent));
    bfs(2, n);

    vector<int> path;
    int node = n;
    while (node != -1)
    {
        path.push_back(node);
        node = parent[node];
    }

    reverse(path.begin(), path.end());

    if (path.size())
        cout << path.size() << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    for (int x : path)
    {
        cout << x << " ";
    }

    return 0;
}