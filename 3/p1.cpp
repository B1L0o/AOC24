#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int is_valid(string line, int idx, long unsigned int length, int enabled)
{
    if (!enabled) return 0;
    int i = 0;
    int n1 = 0; int n2 = 0;
    while (i + idx < length-1 && isdigit(line[i+idx]))
    {
        n1 *= 10;
        n1 += line[idx + i] - '0';
        i++;
    }
    if (line[i + idx] != ',') return 0;
    i++;
    while (i + idx < length-1 && isdigit(line[i+idx]))
    {
        n2 *= 10;
        n2 += line[idx + i] - '0';
        i++;
    }
    if (line[i + idx] != ')') return 0;
    return n1 * n2;
}


int main(void)
{
    string line;
    int result = 0;
    int enabled = 1;
    while(getline(cin,line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (i < line.length() - 5 && line[i] == 'm' && line[i+1] == 'u' && line[i+2] == 'l' && line[i+3] == '(')
            {
                result += is_valid(line,i+4,line.length(), enabled);
                i+= 3;
            }
            if (i < line.length() - 5 && line[i] == 'd' && line[i+1] == 'o' && line[i+2] == '(' && line[i+3] == ')')
            {
                enabled = 1;
                i+= 3;
            }
            if (i < line.length() - 5 && line[i] == 'd' && line[i+1] == 'o' && line[i+2] == 'n' && line[i+3] == 39 && line[i+4] == 't' && line[i+5] == '(' && line[i+6] == ')')
            {
                enabled = 0;
            }
        }
    }
    cout << result << endl;
    return 0;
}
