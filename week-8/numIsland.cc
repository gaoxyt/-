class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        fa = vector<int>(m * n + 1, 0);
        for (int i = 0; i < m * n + 1; i++) {
            fa[i] = i;
        }

        auto pos = [=](int x, int y) {
            return x * n + y;
        };

        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                auto p = pos(i, j);
                if (grid[i][j] == '0') {
                    unionSet(pos(i, j), pos(m - 1, n));
                    continue;
                }
                const int dx[2] = {1, 0};
                const int dy[2] = {0, 1};
                for (int k = 0; k < 2; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni >= m || nj >= n) {
                        continue;
                    }
                    if (grid[ni][nj] == '0') {
                        continue;
                    }
                    unionSet(pos(ni, nj), pos(i, j));
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < m * n; i++) {
            if (fa[i] == i) {
                ans++;
            }
        }
        return ans;
    }

private:
    int find(int x) {
        if (x == fa[x]) {
            return x;
        }
        return fa[x] = find(fa[x]);
    }

    void unionSet(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            fa[x] = y;
        }
    }

private:
    vector<int> fa;
};
