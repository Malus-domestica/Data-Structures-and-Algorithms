#include <iostream>
using namespace std;

string moveToEnd(string str)
{
    if (str.length() == 1)
        return str;
    string reststr = moveToEnd(str.substr(1));
    if (str[0] == 'x')
        return reststr + 'x';
    else
        return str[0] + reststr;
}

int main(int argc, char const *argv[])
{
    cout << moveToEnd("axxbdxcefxhix") << endl;
    return 0;
}
