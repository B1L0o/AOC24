using namespace std;
#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>

int xmas(vector<vector<int>> v , int i, int j, int n, int c)
{
    if (i < 0 || i >= v.size()) return 0;
    if (j < 0 || j >= v[i].size()) return 0;
    if (n == 0 && v[i][j] != 'A') return 0; 
    if (n == 1) return v[i][j] == c;
    int c1 = 0;
    int c2 = 0;
    //M
    c1 += xmas(v,i+1,j+1,1,'M');
    c1 += xmas(v,i+1,j-1,1,'M');  
    c1 += xmas(v,i-1,j+1,1,'M');
    c1 += xmas(v,i-1,j-1,1,'M');
    //S
    c2 += xmas(v,i+1,j+1,1,'S');
    c2 += xmas(v,i+1,j-1,1,'S');  
    c2 += xmas(v,i-1,j+1,1,'S');
    c2 += xmas(v,i-1,j-1,1,'S');
    if (i < 1 || i >= v.size()-1) return 0;
    if (j < 1 || j >= v[i].size()-1) return 0;
    return c1  == 2 and c2 == 2 and v[i-1][j-1] != v[i+1][j+1];

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
            res += xmas(v,i,j,0,0);
        }
    }
    cout << res << endl;
    return res;
}
