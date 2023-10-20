class Solution
{
public:
    int dfs(int src, unordered_map<int, int> &max_time, vector<int> &time, vector<vector<int>> &adj)
    {
        if (max_time[src] > 0)
            return max_time[src];

        int res = time[src - 1];

        for (int i = 0; i < adj[src].size(); i++)
        {
            res = max(res, time[src - 1] + dfs(adj[src][i], max_time, time, adj));
        }
        max_time[src] = res;
        return res;
    }
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<vector<int>> adj(n + 1);

        for (int i = 0; i < relations.size(); i++)
        {
            adj[relations[i][0]].push_back(relations[i][1]);
        }

        for (int j = 0; j < adj.size(); j++)
        {
            cout << j << ": ";
            for (int l = 0; l < adj[j].size(); l++)
                cout << adj[j][l] << " ";
            cout << endl;
        }

        unordered_map<int, int> max_time;
        int mx = INT_MIN;

        for (int i = 1; i <= n; i++)
        {
            max_time[i] = dfs(i, max_time, time, adj);
            mx = max(mx, max_time[i]);
        }
        return mx;
    }
};