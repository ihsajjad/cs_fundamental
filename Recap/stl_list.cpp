#include <bits/stdc++.h>
using namespace std;

int main()
{
    // list<int> ls(5, -1);

    // for(auto child : ls)
    // {
    //     cout << child << " ";
    // }

    // list<int> ls1 = {1, 2, 3};
    // list<int> ls2 = {4, 5, 6};

    // ls2 = ls1;

    // int arr[5] = {1, 2, 3, 4, 5};

    // list<int> ls2(arr, arr + 5);
    // ls2.clear();
    // ls2.push_back(10);
    // ls2.push_front(40);
    // cout << "Size = " << ls2.size() << endl;
    // for (int child : ls2)
    //     cout << child << " ";

    // ls2.pop_back();
    // ls2.pop_front();

    // cout << endl
    //      << "Size = " << ls2.size() << endl;
    // for (int child : ls2)
    //     cout << child << " ";

    // list<int> ls2 = {1, 2, 3, 4, 5};
    // ls2.insert(next(ls2.begin(), 2), 100);
    // cout << endl
    //      << "Size = " << ls2.size() << endl;
    // for (int child : ls2)
    //     cout << child << " ";

    // list<int> ls2 = {1, 2, 3, 4, 5};
    // replace(ls2.begin(), ls2.end(), 4, 200);
    // cout << endl
    //      << "Size = " << ls2.size() << endl;
    // for (int child : ls2)
    //     cout << child << " ";

    // auto it = find(ls2.begin(), ls2.end(), 200);
    // if (it != ls2.end())
    //     cout << "Found" << endl;
    // else
    //     cout << "Not Found" << endl;

    // list<int> ls2 = {1, 9, 8, 4, 4, 4, 2, 3, 4, 5};
    // // ls2.remove(4);
    // // ls2.sort();
    // // ls2.sort(greater<int>()); // sorting decending order
    // // ls2.unique();

    // cout << endl
    //      << "Size = " << ls2.size() << endl;
    // for (int child : ls2)
    //     cout << child << " ";

    list<int> ls2 = {1, 9, 8, 4, 4, 4, 2, 3, 4, 5};

    auto it = next(ls2.begin(), 2);
    cout << *it << endl;

    cout << endl
         << "Size = " << ls2.size() << endl;
    for (int child : ls2)
        cout << child << " ";

    return 0;
}