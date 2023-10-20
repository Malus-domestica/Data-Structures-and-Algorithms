#include <iostream>
using namespace std;

double power(double a, double b)
{
    if (b == 0)
        return 1;
    return a * power(a, b - 1);
}

int main(int argc, char const *argv[])
{
    double a, b;
    cin >> a >> b;
    cout << power(a, b) << endl;
    return 0;
}
