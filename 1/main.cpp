#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    string line;
    int result =  0, first_digit = -1, second_digit = -1;
    while (getline(cin, line)) 
    {
        for (int i = 0; i< line.length(); i++)
        {
            if(line[i] >= '0' && line[i] <= '9')
            {
                first_digit = (first_digit == -1) ? line[i] - '0' : first_digit;
                second_digit = line[i] - '0';
            } 
        }
        int current =  10 * first_digit + second_digit;
        cout << "current: " << current << endl;  
        result += current;
        first_digit = -1, second_digit = -1;

    }
    cout << result << endl;
    return 0;
}
