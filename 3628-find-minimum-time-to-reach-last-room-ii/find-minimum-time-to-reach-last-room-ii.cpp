class Solution {
public:
    int minTimeToReach(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<>> pq;
        pq.push({0, 0, 0});
        vector<int> d = {0, 1, 0, -1, 0};
        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();
            if (t >= dp[i][j])
                continue;
            if (i == n - 1 && j == m - 1)
                return t;
            dp[i][j] = t;
            for (int k = 0; k < 4; ++k) {
                int x = i + d[k], y = j + d[k + 1];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                int cost = (i + j) % 2 + 1;
                int nt = max(g[x][y], t) + cost;
                pq.push({nt, x, y});
            }
        }
        return -1;
    }
};
