#include <iostream>
#include <vector>
#include <queue>

using namespace std;



class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        if (n == 0) return 0;

        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        int distance = -1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto coord = q.front(); q.pop();
                for (int d = 0; d < 4; ++d) {
                    int row = coord.first + directions[d][0];
                    int col = coord.second + directions[d][1];
                    if (row >= 0 && row < m && col >= 0 && col < n && grid[row][col] == 0) {
                        q.push({row, col});
                        grid[row][col] = 1;
                    }
                }          
            }
            ++distance;
        }

        return distance <= 0 ? -1 : distance;
    }

private:
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

};