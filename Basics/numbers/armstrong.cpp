#include <iostream>
#include <cmath>
using namespace std;
//armstrong number : when a number is obtained by adding its digit's cube

int main()
{
    int n, r,original, sum = 0;
    cin >> n;
    original = n;
    while (n)
    {
        r = n % 10;
        sum += pow(r, 3) ;
        n = n / 10;
    }
    if(original == sum )
    cout<<"Number is armstrong number"<<endl;
    else
    cout<<"Number is not armstrong number"<<endl;
}