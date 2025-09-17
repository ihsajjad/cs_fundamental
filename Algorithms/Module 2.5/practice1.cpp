#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int parent[1005];

void dfs(int src, int dst)
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

    int q;
    cin >> q;

    while (q--)
    {

        memset(vis, false, sizeof(vis));
        memset(parent, -1, sizeof(parent));

        int src, dst;
        cin >> src >> dst;

        dfs(src, dst);

        vector<int> path;
        int node = dst;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        int path_length = path.size() - 1;

        if (path_length)
            cout << path_length << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}