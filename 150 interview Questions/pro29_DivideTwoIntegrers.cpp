#include <bits/stdc++.h>
using namespace std;

int divide(int dividend, int divisor)
{
    int cnt = 0;
    int sign = 1;
    if (dividend == divisor)
        return 1;
    else if (dividend == abs(divisor))
        return -1;
    if (dividend < 0 and divisor < 0)
    {
        dividend = abs(dividend);
        divisor = abs(divisor);
    }
    else if (dividend < 0)
    {
        dividend = abs(dividend);
        sign = -1;
    }
    else if (divisor < 0)
    {
        divisor = abs(divisor);
        sign = -1;
    }
    while (dividend > divisor)
    {
        dividend = dividend - divisor;
        cnt++;
    }
    return cnt * sign;
}

int f(int dividend, int divisor)
{
    //edge case
    if()
    int flag = 1; // for sign
    if (dividend < 0 and divisor < 0)
        flag = 1;
    else if (dividend < 0 or divisor < 0)
        flag = -1;

    dividend = abs(dividend);
    divisor = abs(divisor);
    int ans = 0;

    while (divisor<=dividend)
    {
        long int num = divisor;
        int pow2s=1;
        while ((num << 1) < dividend)
        {
            num = num << 1;
            pow2s*=2;
        }
        dividend -= num;
        num = num >> 1;
        // cout<<num<<" "<<dividend<<endl;
        ans += pow2s;
    }
    if (flag == -1)
      return -ans;
    return ans;
}


//good solution aligns with my algo
class Solution
{
public:
    int divide(int dividend, int divisor)
    {

        // Handling corner cases
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        // Converting divisors and dividend to their positive values
        long int dd = abs(dividend), dv = abs(divisor);

        // Result Variables
        int res = 0;
        while (dv <= dd)
        {
            long int mul = dv, tmp = 1;
            while (mul <= dd - mul)
            {
                mul += mul;
                tmp += tmp;
            }
            res += tmp;
            dd -= mul;
        }

        // If either of dividend or divisor is negative our result will be negative
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            return -res;

        return res;
    }
};

int main(int argc, char const *argv[])
{
    cout << f(7, -3) << endl;
    return 0;
}
