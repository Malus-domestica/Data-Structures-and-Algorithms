#include <iostream>
#include <cmath>
using namespace std;

int pyth(int a, int b, int c);

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (pyth(a, b, c))
        cout << "Pythagorian triplet" << endl;
    else
        cout << "Not a Pythagorian triplet" << endl;
    return 0;
}

int pyth(int a, int b, int c)
{
    int psum, check = 0;
    ;
    if (a > b)
    {
        if (a > c)
        {
            psum = pow(b, 2) + pow(c, 2);
            if (pow(a, 2) == psum)
                check = 1;
        }
        else
        {
            psum = pow(b, 2) + pow(a, 2);
            if (pow(c, 2) == psum)
                check = 1;
        }
    }
    else
    {
        if (b > c)
        {
            psum = pow(b, 2) + pow(c, 2);
            if (pow(a, 2) == psum)
                check = 1;
        }
        else
        {
            psum = pow(b, 2) + pow(a, 2);
            if (pow(c, 2) == psum)
                check = 1;
        }
    }
    return check;
}
