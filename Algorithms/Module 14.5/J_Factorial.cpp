#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll fact(ll n)
{
    if (n == 0)
        return 1;
    ll ans = fact(n - 1);
    return ans * n;
}
int main()
{
    int n;
    cin >> n;
    cout << fact(n);
    return 0;
}