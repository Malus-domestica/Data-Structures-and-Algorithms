#include <iostream>
using namespace std;

string remDup(string str)
{
    cout << str << endl;
    if (str.length() == 1)
        return str;
    string reststr = remDup(str.substr(1));
    if (str[0] !=reststr[0])
    {
        cout << "Inside if" << endl;
        return (str[0] + reststr);
    }
    else
        return reststr;
}

int main(int argc, char const *argv[])
{
    cout << remDup("aaaabbbeeecdddd") << endl;
    return 0;
}
