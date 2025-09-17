#include <bits/stdc++.h>
using namespace std;
#define ll long long int
vector<vector<pair<ll, ll>>> adj_list;
vector<ll> dst;
vector<ll> parent;

void dijkstra(ll src)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, src});
    dst[src] = 0;
    while (!pq.empty())
    {
        auto par = pq.top();
        pq.pop();
        ll par_node = par.second;
        ll par_dis = par.first;

        for (auto child : adj_list[par_node])
        {
            ll child_node = child.first;
            ll c_dst = child.second;
            ll new_dst = par_dis + c_dst;
            if (new_dst < dst[child_node])
            {
                dst[child_node] = new_dst;
                pq.push({new_dst, child_node});
                parent[child_node] = par_node;
            }
        }
    }
}

int main()
{
    ll n, e;
    cin >> n >> e;
    adj_list.assign(n + 1, vector<pair<ll, ll>>());
    dst.assign(n + 1, LLONG_MAX);
    parent.assign(n + 1, -1);
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        adj_list[a].push_back({b, c});
        adj_list[b].push_back({a, c});
    }

    dijkstra(1);

    if (dst[n] == LLONG_MAX)
    {
        cout << -1 << endl;
    }
    else
    {
        ll node = n;
        vector<ll> path;
        while (node != -1)
        {
            path.push_back(node);
            node = parent[node];
        }

        reverse(path.begin(), path.end());
        for (int child : path)
            cout << child << " ";
    }
    return 0;
}