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
    if (leader1 == leader2)
        return;

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

    int n, e;
    cin >> n;
    e = n - 1;

    par.assign(n + 1, -1);
    group_size.assign(n + 1, 1);

    vector<pair<int, int>> rmv;
    vector<pair<int, int>> create;

    while (e--)
    {
        int a, b;
        cin >> a >> b;

        int leaderA = dsu_find(a);
        int leaderB = dsu_find(b);
        if (leaderA == leaderB)
            rmv.push_back({a, b});
        else
            dsu_union(a, b);
    }

    for (int i = 2; i <= n; i++)
    {
        int leaderA = dsu_find(1);
        int leaderB = dsu_find(i);

        if (leaderA != leaderB)
        {
            create.push_back({1, i});
            dsu_union(1, i);
        }
    }

    cout << rmv.size() << endl;
    for (int i = 0; i < rmv.size(); i++)
    {
        cout << rmv[i].first << " " << rmv[i].second << " " << create[i].first << " " << create[i].second << endl;
    }

    return 0;
}