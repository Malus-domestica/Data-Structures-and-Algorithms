#include <iostream>
using namespace std;

double fact(int n)
{
    if (n == 0)//base condition
        return 1;
    else
        return n * fact(n - 1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}
