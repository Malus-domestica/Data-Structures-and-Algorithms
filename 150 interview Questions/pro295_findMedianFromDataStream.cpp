#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
private:
    vector<int> arr;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        arr.push_back(num);
    }

    double findMedian()
    {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int md1, md2;
        if (n % 2 == 0)
        {
            md2 = n / 2;
            md1 = md2 - 1;
            double ans = (double)(arr[md2] + arr[md1]) / 2;
            return ans;
        }
        else
        {
            md1 = n / 2;
            return arr[md1];
        }
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}

