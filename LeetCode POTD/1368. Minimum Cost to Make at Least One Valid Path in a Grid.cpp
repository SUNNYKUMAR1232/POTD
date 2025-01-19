//https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/


class Solution {
public:
    unordered_map<int, pair<int, int>> dirs = {
        {1, {0, 1}},  // Right
        {2, {0, -1}}, // Left
        {3, {1, 0}},  // Down
        {4, {-1, 0}}  // Up
    };
    // Approach 2: Using Dijktra Backtrecking
    // int Solve(vector<vector<int>>& mat, int row, int col, int n, int m,
    // vector<vector<bool>>& visit, int cost) {
    //     if (row == n - 1 && col == m - 1) {
    //         return cost;
    //     }
    //     visit[row][col] = true; // Mark as visited
    //     int minCost = INT_MAX;

    //     // Explore all directions
    //     for (auto& [key, dir] : dirs) {
    //         int dx = dir.first;
    //         int dy = dir.second;
    //         int altRow = row + dx;
    //         int altCol = col + dy;

    //         if (altRow >= 0 && altRow < n && altCol >= 0 && altCol < m &&
    //         !visit[altRow][altCol]) {
    //             // Add extra cost if moving in a direction different from the
    //             current direction int nextCost = cost + ((mat[row][col] !=
    //             key) ? 1 : 0); minCost = min(minCost, Solve(mat, altRow,
    //             altCol, n, m, visit, nextCost));
    //         }
    //     }

    //     visit[row][col] = false; // Backtrack
    //     return minCost;
    // TC : O(4^(n*m))
    // SC : O((n*m))
    // }
    // Approach 2: Using Dijktra Algorithms
    void Solve(vector<vector<int>>& mat, int row, int col, int n, int m,
               vector<vector<int>>& ans) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>, greater<>>
            q;
        q.push({0, {row, col}});
        ans[row][col] = 0;

        while (!q.empty()) {
            auto it = q.top();
            q.pop();

            int _row = it.second.first;
            int _col = it.second.second;
            int cost = it.first;

            // Skip if this is not the optimal cost for the current cell
            if (ans[_row][_col] < cost) {
                continue;
            }

            // Explore neighbors
            for (auto& [key, dir] : dirs) {
                int dx = dir.first;
                int dy = dir.second;
                int altRow = _row + dx;
                int altCol = _col + dy;

                if (altRow >= 0 && altRow < n && altCol >= 0 && altCol < m) {
                    // Calculate cost to move to the neighbor
                    int newCost = cost + ((mat[_row][_col] != key) ? 1 : 0);

                    // Update cost if a better path is found
                    if (newCost < ans[altRow][altCol]) {
                        ans[altRow][altCol] = newCost;
                        q.push({newCost, {altRow, altCol}});
                    }
                }
            }
        }
        // TC : O(n*m*log(n*m))
        // SC : O((n*m))
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n, vector<int>(m, INT_MAX)); // Visited matrix
        Solve(grid, 0, 0, n, m, ans);
        return ans[n - 1][m - 1];
    }
};