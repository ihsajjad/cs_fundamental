#include <bits/stdc++.h>
using namespace std;
int n, e;
vector<int> dst;
vector<vector<pair<int, int>>> adj_list;
vector<int> path;
bool is_vis = false;

void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();

        int par_node = par.second;
        int par_dst = par.first;

        if (par_node == n)
            is_vis = true;

        for (auto child : adj_list[par_node])
        {
            int c_node = child.first;
            int c_dst = child.second;

            if (par_dst == INT_MAX)
                continue;

            int new_dst = par_dst + c_dst;

            if (new_dst < dst[c_node])
            {
                dst[c_node] = new_dst;
                pq.push({new_dst, c_node});
                path[c_node] = par_node;
            }
        }
    }
}

void print_path(int src)
{
    if (src == -1)
        return;

    print_path(path[src]);
    cout << src << " ";
}

int main()
{

    cin >> n >> e;
    adj_list.assign(n + 5, vector<pair<int, int>>());
    dst.assign(n + 5, INT_MAX);
    path.assign(n + 2, -1);

    dst[1] = 0;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(1);
    if (is_vis)
        print_path(n);
    else
        cout << -1 << endl;
    return 0;
}