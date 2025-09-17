#include <bits/stdc++.h>
using namespace std;

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

int dst[1005];

int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> edge_list;

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    for (int i = 0; i < n; i++)
        dst[i] = INT_MAX;

    dst[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (auto ed : edge_list)
        {
            int a, b, c;
            a = ed.a;
            b = ed.b;
            c = ed.c;

            if (dst[a] != INT_MAX && dst[a] + c < dst[b])
                dst[b] = dst[a] + c;
        }
    }

    bool cycle = false;
    for (auto ed : edge_list)
    {
        int a, b, c;
        a = ed.a;
        b = ed.b;
        c = ed.c;

        if (dst[a] != INT_MAX && dst[a] + c < dst[b])
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Negative weighted cycle dected\n";
    else
    {
        for (int i = 0; i < n; i++)
            cout << i << " -> " << dst[i] << endl;
    }

    return 0;
}