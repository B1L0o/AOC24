using namespace std;
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <string>


unsigned long long count_numbers(vector<long long> res)
{
    unsigned long long result = 0;
    for(size_t i = 0; i < res.size(); i++)
    {
        if(res[i] != -1) result += i * res[i];
    }
    return result;
}

vector<long long> compact(vector<long long> line)
{
    //cout << line << endl;
    vector<long long> copy = line;
    int i = 0, j = line.size() - 1;
    while (i<j)
    {
        while(j > 0 && copy[j] == -1) j--;
        if(line[i] == -1)
        {
            line[i] = copy[j];
            line[j] = -1;
            j--;
            //cout << line << endl;
        }
        i++;
    }
    /*vector<unsigned long long>result;
    i = 0;
    while (line[i] != '.')
    {
        result.push_back(line[i]);
        i++;
    }*/
    return line;
}

int main(void)
{
    string line;
    getline(cin,line);
    string res;
    int idx = 0;
    vector<long long> v;
    for (size_t i = 0; i < line.length(); i++)
    {
        for(int j = 0; j < line[i] - '0'; j++)
        {
            v.push_back((i%2 == 1) ? -1 : idx);
        }
        idx += (i%2 == 0);
    }
    v = compact(v);
    cout << res << endl;
    unsigned long long result = count_numbers(v);
    //cout << res << endl;
    cout << result;
    return 0;
}
