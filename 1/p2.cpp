#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(void)
{
    int n1, n2, count = 0;
    vector<int> l1;
    map<int,int> map;
    while (cin >> n1 && cin >> n2) 
    {  
        l1.push_back(n1);
        if (!map[n2])
        {
            map[n2] = 1;
        }
        else
        {
            map[n2] += 1;
        }
        
    }
    for (int i = 0; i < l1.size(); i++)
    {
        count += l1[i] * map[l1[i]];
    }
    cout << count << endl;    
    return 0;
}
