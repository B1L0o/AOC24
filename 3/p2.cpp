#include <string>
#include <iostream>
#include <sstream>
#include <vector>


int check_vector(vector<int> v, int idx)
{
        for (int i = idx+1; i < v.size(); i++)
            v[i - 1] = v[i];
        v.pop_back();
        int number;
        int first = v[0];
        int second = v[1];
        int found = 1;
        int slope = first - second;
        if (abs(slope) > 3 || slope == 0) found = 0;
        int current = second;
        int i = 2;
        while (i < v.size()) 
        {
            number = v[i];
            if((number - current) * -slope <= 0 || abs(number - current) > 3)
            {
                found = 0;
                break;
            }
            else
            {
                current = number;
            }
            i++;

        }
        return found;
}

int main(void)
{
    string line;
    int result = 0;
    int number;
    while(getline(cin,line))
    {
        stringstream stream(line);
        vector<int> v;
        while (stream >> number) 
        {
            v.push_back(number);
        }
        for(int i = 0; i < v.size(); i++)
        {
            if (check_vector(v,i))
            {
                result ++;
                break;
            }

        }
    }
    cout << result << endl;
}
