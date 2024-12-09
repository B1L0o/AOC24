using namespace std;
#include <vector>
#include <iostream>
#include <string>

int path_count(vector<vector<int>> &v, size_t x, size_t y)
{
    int count = 0, i = -1,j = 0;
    while(1)
    {
        while(x < v.size() && x >= 0 && y >= 0 && y < v[x].size() and (v[x][y] != '#' ))
        {
            if (v[x][y] != 'X')
                count ++;
            v[x][y] = 'X';
            x+=i;
            y+=j;
        }
        if (x >= v.size() || x < 0 || y < 0 || y >= v[x].size())
        {
            return count;
        }
        x -= i;
        y -= j;
        int temp = i;
        i = j;
        j = -temp;
    }
    return 0;
}

int main(void)
{
    string line;
    vector<vector<int>> v;
    size_t j = 0, x, y;
    while (getline(cin,line))
    {
        vector<int> temp;
        for (size_t i = 0; i < line.length(); i++)
        {
            if (line[i] == '^') 
            {
                y = i;
                x = j;
            }
            temp.push_back(line[i]);
        }
        v.push_back(temp);
        j++;
    }
    int counter = path_count(v,x,y);
    print_vector(v);
    cout << counter;
    return counter;
}
