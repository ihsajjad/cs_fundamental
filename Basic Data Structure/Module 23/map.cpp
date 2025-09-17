#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<string, int> mp;
    mp["Shakib"] = 100;
    mp["Tamim"] = 50;
    mp["Ajad"] = 80;
    mp["Jahid"] = 30;



    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    // if (mp.count("Tamim"))
    //     cout << "Ache" << endl;
    // else
    //     cout << "Nai" << endl;
    
    

    return 0;
}