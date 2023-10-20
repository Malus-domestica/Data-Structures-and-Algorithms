#include <iostream>
using namespace std;

void stringRep(string str)
{
    if (str.length() == 0)
        return;
    if (str[0] == 'p' && str[1] == 'i')
    {
        cout << 3.14;
        stringRep(str.substr(2));
    }
    else
    {
        cout << str[0];
        stringRep(str.substr(1));
    }
}

int main(int argc, char const *argv[])
{
    stringRep("pipppxpipx");
    cout << endl;
    return 0;
}
