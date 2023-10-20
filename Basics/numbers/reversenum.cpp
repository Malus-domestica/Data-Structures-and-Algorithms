#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, r, rev_n = 0;
    cin >> n;
    while (n)
    {
        r = n % 10;
        rev_n = r + rev_n * 10;
        n = n / 10;
    }
    cout<<"Reverse of number: "<<rev_n<<endl;
}