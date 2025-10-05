#include <bits/stdc++.h>
using namespace std;
int par[1005];
int group_size[1005];

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    node = par[node];
    int leader = dsu_find(node);
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);
    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader1] += group_size[leader2];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader2] += group_size[leader1];
    }
}

class Edge
{
public:
    int a, b, c;

    Edge(int a, int b, int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
};

bool cmp(Edge l, Edge r)
{
    return l.c < r.c;
}

int main()
{

    int n, e;
    cin >> n >> e;

    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    vector<Edge> edge_list;
    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    sort(edge_list.begin(), edge_list.end(), cmp);
    int total_cost = 0;

    for (auto e : edge_list)
    {
        int leaderA = dsu_find(e.a);
        int leaderB = dsu_find(e.b);

        if (leaderA != leaderB)
        {
            dsu_union(e.a, e.b);
            total_cost += e.c;
        }
    }

    cout << total_cost << endl;

    return 0;
}