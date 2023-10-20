class Solution
{
public:
    int trailingZeroes(int n)
    {
        int sum = 0;
        // we'll count only 5s
        while (n > 0)
        {
            sum += n / 5;
            n = n / 5;
        }
        return sum;
    }
};
// we need find number 2s and 5s
// but finding 5s will work because 2s will exceed 5s
// to find 5s for example in 150
// if we divide once we'll get 30 5s
// but there are terms containing two or more fives
// that means that number(n/5) can again be divided by 5 (n/5 wala number)to give more 5s
// untill it becomes 0