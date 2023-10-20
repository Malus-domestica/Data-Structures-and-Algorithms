class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        stack<vector<int>> stk;
        //  for(int i=0;i<intervals.size();i++){
        //      cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
        //  }
        stk.push(intervals[0]);

        int n = intervals.size();

        for (int i = 1; i < n; i++)
        {
            auto ele = stk.top();
            if (ele[1] >= intervals[i][0] and ele[1] <= intervals[i][1])
            {
                ele[1] = intervals[i][1];
                stk.pop();
                stk.push(ele);
            }
            else if (ele[1] < intervals[i][0])
                stk.push(intervals[i]);
        }

        int i = 0, m = stk.size();
        cout << "size of stack: " << m << endl;
        for (int i = 0; i < m; i++)
        {
            ans.push_back(stk.top());
            stk.pop();
        }

        return ans;
    }
};