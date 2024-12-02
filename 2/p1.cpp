using namespace std;
#include <string>
#include <iostream>
#include <sstream>

int main(void)
{
    string line;
    int result = 0;
    while(getline(cin,line))
    {
        stringstream stream(line);
        int first, second, number;
        stream >> first >> second;
        int found = 1;
        int slope = first - second;
        if (abs(slope) > 3 || slope == 0) found = 0;
        int current = second;
        while (stream >> number) 
        {
            if((number - current) * -slope <= 0 || abs(number - current) > 3)
            {
                found = 0;
                break;
            }
            else
            {
                current = number;
            }

        }
        result += found;
    }
    cout << result << endl;
}
