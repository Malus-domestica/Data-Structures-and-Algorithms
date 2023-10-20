#include <bits/stdc++.h>
using namespace std;

int maxArea(vector<int> &height)
{
    int n = height.size();
    int maxar = 0;
    int i, j;
    i = 0;
    j = n - 1;
    while (i < j)
    {
        int area = (j - i) * (min(height[i], height[j]));
        maxar = max(maxar, area);
        if (height[i] > height[j])
            j--;
        else
            i++;
    }
    return maxar;
}

int main(int argc, char const *argv[])
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
    return 0;
}
