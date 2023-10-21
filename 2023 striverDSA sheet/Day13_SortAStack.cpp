#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int element)
{
    if (st.empty() || element > st.top())
        st.push(element);
    else
    {
        int top_element = st.top();
        st.pop();
        sortedInsert(st, element);
        st.push(top_element);
    }
}
void sortStack(stack<int> &st)
{
    // Write your code here
    if (!st.empty())
    {
        int top_element = st.top();
        st.pop();
        sortStack(st);
        sortedInsert(st, top_element);
    }
}

int main(int argc, char const *argv[])
{
    return 0;
}

