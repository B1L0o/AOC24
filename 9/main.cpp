using namespace std;
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <string>


unsigned long long count_numbers(string res)
{
    unsigned long long result = 0;
    for(size_t i = 0; i < res.length(); i++)
    {
        result += i * res[i];
    }
    return result;
}

string compact(string line)
{
    //cout << line << endl;
    string copy = line;
    int i = 0, j = line.length() - 1;
    while (i<j)
    {
        while(j > 0 && copy[j] == '.') j--;
        if(line[i] == '.')
        {
            line[i] = copy[j];
            line[j] = '.';
            j--;
            //cout << line << endl;
        }
        i++;
    }
    string result;
    i = 0;
    while (line[i] != '.')
    {
        result += line[i];
        i++;
    }
    return result;
}

int main(void)
{
    string line;
    getline(cin,line);
    string res;
    int idx = 0;
    for (size_t i = 0; i < line.length(); i++)
    {
        for(int j = 0; j < line[i] - '0'; j++)
        {
            res += (i%2 == 1) ? '.' : idx;
        }
        idx += (i%2 == 0);
    }
    cout << res << endl;
    res = compact(res);
    cout << res << endl;
    unsigned long long result = count_numbers(res);
    //cout << res << endl;
    cout << result;
    return 0;
}
