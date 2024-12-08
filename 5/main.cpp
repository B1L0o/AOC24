using namespace std;
#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


void print_map(map<int,vector<int>> map)
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

void print_vector(vector<int> v)
{
    for (auto i : v) cout << i << " ";
    cout << endl;
}




bool is_present(int x, vector<int> v)
{
    for(size_t i = 0; i < v.size(); i++)
    {
        if (x == v[i]) return true;
    }
    return false;
}

int isvalid(vector<int>&v, map<int,vector<int>> &map)
{
    for (size_t i = 0; i< v.size(); i++)
    {
        for (size_t j = 0; j < i; j++)
        {
            if (!is_present(v[j],map[v[i]])) return 0;
        }
    }
    //print_vector(v);
    return 1;
}

int parse_input(string line, map<int,vector<int>> &map)
{
    if (line.length() == 0) return 0;
    replace (line.begin(),line.end(), ',',' ');
    stringstream stream(line);
    vector<int> v;
    int number;
    while (stream >> number) 
    {
        v.push_back(number);
    }
    //print_vector(v);
    if (isvalid(v,map)) return v[v.size()/2];
    return 0;
}

void fill_map(string line, map<int, vector<int>> &map)
{
     //print_map(map);
     int n1 = 0, n2 = 0;
     bool found = false;
     for (size_t i =0; i < line.length(); i++)
     {
        if (line[i] == '|') 
        {
            found = true;
            i ++;
        }
        if (found)
        {
            n2 *= 10;
            n2 += line[i] - '0';
        }
        else
        {
            n1 *= 10;
            n1 += line[i] - '0';
        }
     }
     if (map.count(n2) > 0) map[n2].push_back(n1);
     else map[n2] = {n1};
}

int main(void)
{
    string line;
    map<int,vector<int>> map;
    bool found = false;
    int res = 0;
    while (getline(cin,line))
    {
        if(line.length() == 0)
        {
            found = true;
        }
        if (found) res += parse_input(line,map);
        else fill_map(line,map);
    }
    cout << res << endl;
    return res;
}
