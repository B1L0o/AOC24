using namespace std;
#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>

int xmas(vector<vector<int>> v , int i, int j, int x, int y, int n)
{
    if (i < 0 || i >= v.size()) return 0;
    if (j < 0 || j >= v[i].size()) return 0;
    if (n == 0 && v[i][j] != 'X') return 0;
    if (n == 1 && v[i][j] != 'M') return 0;
    if (n == 2 && v[i][j] != 'A') return 0;
    if (n == 3) return v[i][j] == 'S';
    int res = 0;
    if (n == 0)
    {
        for(int a = -1; a <= 1; a++)
        {
            for (int b = -1; b <= 1; b++)
            {
                res += xmas(v,i+a,j+b,a,b,n+1);

            }
        }
    }
    else
    {
        res += xmas(v,i+x,j+y,x,y,n+1);
    } 
    return res;
}

int main(void)
{
    string line;
    vector<vector<int>>  v;
    while (getline(cin,line))
    {
        vector<int> t;
        for (int j =0; j < line.length(); j++)
        {
            t.push_back(line[j]);
        }
        v.push_back(t);
    }
    int res = 0;
    for (int i = 0; i <v.size(); i++)
    {
        for (int j = 0; j < v[i].size();j++)
        {

            res += xmas(v,i,j,0,0,0);
        }
    }
    cout << res << endl;
    return res;
}
