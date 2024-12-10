using namespace std;
#include <vector>
#include <iostream>
#include "../utils/utils.h"



void fill_freq(vector<vector<int>> map, vector<vector<int>> &freq, size_t y, size_t x, size_t i, size_t j,char antenna)
{
    size_t dy = (i-y) * 2;
    size_t dx = (j-x) * 2;
    size_t new_y = dy + y;
    size_t new_x = dx + x;
    if (new_y >= 0 && new_y < map.size() && new_x >= 0 && new_x < map[0].size() 
            && map[new_y][new_x] != antenna)
    {
        freq[new_y][new_x]='#'; 
    }
}

void fill_locations(vector<vector<int>> map, vector<vector<int>> &freq, size_t y, size_t x)
{

    char antenna = map[y][x];
    for(size_t i = 0; i < map.size(); i++)
    {
        for(size_t j = 0; j < map[i].size(); j++)
        {
            if(map[i][j] == antenna && x != i && y!=j)
            {
                fill_freq(map,freq,y,x,i,j,antenna);
            }
        }
    }
}

int main(void)
{
    string line;
    vector<vector<int>> map;
    vector<vector<int>> freq;
    int count = 0;
    while(getline(cin,line))
    {
        vector<int> v1,v2;
        for (size_t i = 0; i< line.length(); i++)
        {
            v1.push_back(line[i]);
            v2.push_back('.');
        }
        map.push_back(v1);
        freq.push_back(v2);
    }
    for (size_t i = 0; i < map.size(); i++)
    {
        for (size_t j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] != '.') 
            {
                fill_locations(map,freq,i,j); 
            }
        }
    }
    for (size_t i = 0; i < map.size(); i++)
    {
        for (size_t j = 0; j < map[i].size(); j++)
        {
                count += (freq[i][j] == '#');
        }
    }
    DBG_VV(freq);
    cout << count;
}
