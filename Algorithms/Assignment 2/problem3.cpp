#include <bits/stdc++.h>
using namespace std;

vector<int> par;
vector<int> group_size;

int dsu_find(int node)
{
    if (par[node] == -1)
        return node;
    int leader = dsu_find(par[node]);
    par[node] = leader;
    return leader;
}

void dsu_union(int node1, int node2)
{
    int leader1 = dsu_find(node1);
    int leader2 = dsu_find(node2);

    if (group_size[leader1] >= group_size[leader2])
    {
        par[leader2] = leader1;
        group_size[leader2] += group_size[leader1];
    }
    else
    {
        par[leader1] = leader2;
        group_size[leader1] += group_size[leader2];
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    par.assign(n + 1, -1);
    group_size.assign(n + 1, 1);
    int count = 0;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leader1 = dsu_find(a);
        int leader2 = dsu_find(b);

        if (leader1 == leader2)
            count++;
        else
            dsu_union(a, b);
    }

    cout << count;

    return 0;
}