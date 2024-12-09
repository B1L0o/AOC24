using namespace std;
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "../utils/utils.h"


bool is_valid(int n,vector<int>v,char c,size_t idx,int sum)
{ 
    if (v.size() == 0) return false;
    if (v.size() == 1) return n == v[1];
    if(idx == 0) 
    {
        sum = v[idx];
        return is_valid(n,v,'+',1,sum) || is_valid(n,v,'*',1,sum) || is_valid(n,v,'|',1,sum);
    }
    if(idx == v.size()) 
    {
        return sum == n;
    }
    if (c == '+') sum += v[idx];
    if (c == '*') sum *= v[idx];
    if (c == '|') sum = stoll(to_string(sum) + to_string(v[idx]));
    return is_valid(n,v,'+',idx+1,sum) || is_valid(n,v,'*',idx+1,sum) || is_valid(n,v,'|',idx+1,sum);;
}

int main(void)
{
    string line;
    unsigned long long num;
    unsigned long long n;
    unsigned long long res = 0;
    while (getline(cin,line))
    {
        vector<int> v;
        replace(line.begin(),line.end(), ':',' ');
        stringstream stream(line);
        stream >> num;
        while(stream)
        {
            stream >> n;
            v.push_back(n);
        }
        // last element should not be included
        if(v.size() > 0)v.pop_back();
        if (is_valid(num,v,0,0,0)) res += num;
        DBG_V(v);
    }
    cout << res;
    return 0;
}
