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
        int tolerate = 1;
        int slope = first - second;
        if (abs(slope) > 3 || slope == 0) tolerate = 0;
        cout << "slope " << slope << endl;
        int current = second;
        while (stream >> number) 
        {
            cout << "Current " << number - current << endl;
            if((number - current) * -slope <= 0 || abs(number - current) > 3)
            {
                if (tolerate) 
                {
                    tolerate = 0;
                }
                else
                {
                    cout << "wrong num " << number;
                    found = 0;
                    break;
                }
            }
            else
            {
                current = number;
            }

        }
        if (found)
        {
            cout << "safe" << endl;
        }
        else
        {
            cout << "not safe" << endl;
        }
        result += found;
    }
    cout << result << endl;
}
