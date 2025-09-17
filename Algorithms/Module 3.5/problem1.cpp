// Question: You will be given an undirected graph as input. Then you will be given a node N. You need to tell the number of nodes that can be visited from node N.

#include <bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];

int bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    int count = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        count++;

        for (int child : adj_list[par])
        {
            if (!vis[child])
            {
                q.push(child);
                vis[child] = true;
            }
        }
    }
    return count;
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
    int src;
    cin >> src;

    int time = bfs(src);
    cout << time;

    return 0;
}