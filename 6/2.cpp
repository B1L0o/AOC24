using namespace std;
#include <vector>
#include <iostream>
#include <string>

void print_vector(vector<vector<int>> v)
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


bool change_direction(vector<vector<int>> v, size_t x, size_t y, int i, int j)
{  
        if (x == 0 && i == -1) return false;
        if (x == v.size()-1 && i== 1) return false;
        if (y == 0 && j == -1) return false;
        if (y == v[i].size()-1 && j == 1) return false;
        if (v[x+i][y+j] == 'O') return false;
        //if (v[x+i][y+j] == '#') return false;
        v[x+i][y+j] = 'O';
        while(1)
        {

            while(x < v.size() && x >= 0 && y >= 0 && y < v[x].size() and v[x][y] != '#' and v[x][y] != 'O')
            {
                if (v[x][y] == '.') v[x][y] = '0';
                if (v[x][y] != '#' && v[x][y] != '^' && v[x][y] != '.') v[x][y] ++;
                if (v[x][y] == '4') 
                {
                    return true;
                }
                x+=i;
                y+=j;
            }
            if (x >= v.size() || x < 0 || y < 0 || y >= v[x].size())
            {
                return false;
            }
            x -= i;
            y -= j;
            int temp = i;
            i = j;
            j = -temp;
        }
        return true;

}
int path_count(vector<vector<int>> &v, size_t x, size_t y)
{
    int count = 0, i = -1,j = 0;
    while(1)
    {

        while(x < v.size() && x >= 0 && y >= 0 && y < v[x].size() and (v[x][y] != '#' ))
        {
            if(change_direction(v,x,y,i,j) == true and v[x+i][y+j] != '#')// DEUXIEME CONDITION POSE PROBLEME ? 
            {
                v[x+i][y+j] = 'O';
                count ++;
            }
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
