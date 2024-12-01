#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n1, n2, count = 0;
    vector<int> l1, l2;
    while (cin >> n1 && cin >> n2) 
    {  
        l1.push_back(n1);
        l2.push_back(n2);
    }
    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());
    for (int i = 0; i < l1.size(); i++)
    {
        count += abs(l1[i] - l2[i]);
    }
    cout << count << endl;    
    return 0;
}
