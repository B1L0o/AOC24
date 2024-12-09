using namespace std;
#include <vector>
#include <iostream>
#include <map>
#include "utils.h"

void DBG_VV(vector<vector<int>> v)
{
    for (size_t i = 0; i < v.size(); i++)
    {
        for (size_t j = 0; j < v[i].size(); j++)
        {
            printf("%c ",v[i][j]);
        }
        cout << endl;
    }
    cout << endl;
}


void DBG_MV(map<int,vector<int>> map)
{
    //PRINT MAP CONTENT
    for(auto it = map.cbegin(); it != map.cend(); ++it)
    {
         cout << "key:" << it->first << "| values:  ";
         for (auto i : it->second) cout << i << " ";
         cout << endl;
    }
    cout << endl;
}

void DBG_V(vector<int> v)
{
    for (auto i : v) cout << i << " ";
    cout << endl;
}


