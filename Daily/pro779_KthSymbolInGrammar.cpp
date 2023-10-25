#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int kthGrammar(int n, int k)
    {

        int first = 1, last = pow(2, n - 1);
        int cur = 0;

        for (int i = 1; i < n; i++)
        {
            int mid = (first + last) / 2;
            if (k <= mid)
            {
                last = mid; // cur doesnt change when we go to left half
            }
            else
            {
                first = mid + 1;
                cur = cur ^ 1;
            }
        }
        return cur;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
