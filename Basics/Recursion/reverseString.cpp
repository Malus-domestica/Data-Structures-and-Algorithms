#include <iostream>
using namespace std;

void revstring(string str)
{
    if (str.length() == 0)
    {
        return;
    }
    string ros = str.substr(1);
    revstring(ros);
    cout << str[0] ;
}

int main(int argc, char const *argv[])
{
    revstring("binod");
    cout<<endl;
    return 0;
}
