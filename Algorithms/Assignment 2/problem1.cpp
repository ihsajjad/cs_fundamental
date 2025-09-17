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

vector<Edge> edge_list;
vector<long long int> dst;
bool is_cycle = false;

int main()
{
    int n, e;
    cin >> n >> e;

    dst.assign(n + 2, LLONG_MAX);

    while (e--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge_list.push_back(Edge(a, b, c));
    }

    int src, tc;
    cin >> src >> tc;
    dst[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (Edge e : edge_list)
        {
            int a, b, c;
            a = e.a;
            b = e.b;
            c = e.c;

            if (dst[a] == LLONG_MAX)
                continue;

            if (dst[a] + c < dst[b])
                dst[b] = dst[a] + c;
        }
    }

    for (Edge e : edge_list)
    {
        int a, b, c;
        a = e.a;
        b = e.b;
        c = e.c;

        if (dst[a] == LLONG_MAX)
            continue;

        if (dst[a] + c < dst[b])
            is_cycle = true;
    }

    if (is_cycle)
    {
        cout << "Negative Cycle Detected" << endl;
        return 0;
    }

    while (tc--)
    {
        int d;
        cin >> d;

        if (dst[d] == LLONG_MAX)
            cout << "Not Possible" << endl;
        else
            cout << dst[d] << endl;
    }

    return 0;
}