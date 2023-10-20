#include <iostream>
using namespace std;

//gives nth fibonacci number starting from 0

int fibonacci(int n)
{
    int sum;
    //base condition
    if (n == 1 || n==0)
    {
        return n;
    }

    sum = fibonacci(n - 1) + fibonacci(n - 2);
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << fibonacci(n)<<endl;
    return 0;
}
