#include <bits/stdc++.h>
using namespace std;

vector<string> fizzBuzz(int n)
{
    vector<string> answer;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 and i % 5==0)
            answer.push_back("FizzBuzz");
        else if (i % 3 == 0)
            answer.push_back("Fizz");
        else if (i % 5 == 0)
            answer.push_back("Buzz");
        else
            answer.push_back(to_string(i));
    }
    return answer;
}

int main(int argc, char const *argv[])
{
    int n = 15;
    vector<string> arr = fizzBuzz(n);
    for (auto a : arr)
        cout << a << "  ";
    cout << endl;
    return 0;
}
