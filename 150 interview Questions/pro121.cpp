#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int lsf = INT_MAX;
    int op = 0;
    int pist = 0;
    int len = prices.size();
    for (int i = 0; i < len; i++)
    {
        if (prices[i] < lsf)// if we found new buy value which is more smaller then previous one
            lsf = prices[i];// update our least so far
        pist = prices[i] - lsf;// calculating profit if sold today by, Buy - sell
        if (op < pist) // if pist is more then our previous overall profit
            op = pist;// update overall profit
    } 
    return op;
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        int profit = 0;
        int a = prices[0];//buying on first day
        for(int i=1;i<n;i++){
            profit = max(profit,prices[i]-a);
            a = min(a,prices[i]);//keeping left minimum
        }
        return profit;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> prices = {1, 2};
    cout << maxProfit(prices) << endl;
    return 0;
}
