class Solution {
public:
    vector<vector<int>> dp;

    int solve(int start, int end, vector<int> &cuts) {
        if (start > end)
            return 0;

        if (dp[start][end] != -1)
            return dp[start][end];

        int mini = INT_MAX;
        for (int i = start; i <= end; i++) {
            int cost = cuts[end + 1] - cuts[start - 1] 
                       + solve(start, i - 1, cuts) 
                       + solve(i + 1, end, cuts);
            mini = min(mini, cost);
        }

        return dp[start][end] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        dp.resize(m, vector<int>(m, -1));
        return solve(1, m - 2, cuts);
    }
};

