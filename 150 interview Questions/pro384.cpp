#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> array;

public:
    Solution(vector<int> &nums)
    {
        array = nums;
    }

    vector<int> reset()
    {
        return array;
    }
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    vector<int> shuffle()
    {
        vector<int> temp = array;
        for (int i = n - 1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            swap(&temp[i], &temp[j]);
        }
        return temp;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
