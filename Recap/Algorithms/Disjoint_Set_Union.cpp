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

int main()
{
    int n, m;
    cin >> n >> m;

    memset(par, -1, sizeof(par));
    memset(group_size, 1, sizeof(group_size));

    while (m--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);

        if (leaderA == leaderB)
            cout << "Cycle Detected/n";
        else
            dsu_union(a, b);
    }

    for (int i = 0; i <= n; i++)
        cout << i << " -> " << par[i] << endl;

    return 0;
}