#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (!numerator)
            return "0";
        string ans = "";
        // to append the sign to ans xor is performed
        if (numerator > 0 xor denominator > 0)
            ans += '-';
        long num = labs(numerator), den = labs(denominator);
        long q = num / den;
        long r = num % den;
        ans += to_string(q);

        // case 1 when remainder is zero
        if (r == 0)
            return ans;

        ans += '.';
        unordered_map<long, int> mp;
        // case 2 when remainder is not zero
        while (r != 0)
        {
            if (mp.find(r) != mp.end())
            {
                int pos = mp[r];
                ans.insert(pos, "(");
                ans += ')';
                break;
            }
            else
            {
                mp[r] = ans.length(); // this is used for the length at which remainder is getting repeated(take len before appending r in order to get correct position)
                // simple maths
                r *= 10;
                q = r / den;
                r = r % den;
                ans += to_string(q); // always append quotient to the string
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}
