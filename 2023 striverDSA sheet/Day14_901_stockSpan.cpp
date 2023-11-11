#include <bits/stdc++.h>
using namespace std;

class StockSpanner
{
    stack<pair<int, int>> stk;

public:
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!stk.empty() and price >= stk.top().first)
        {
            auto ele = stk.top();
            span += ele.second;
            stk.pop();
        }
        stk.push({price, span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */