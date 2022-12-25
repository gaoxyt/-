class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        fa = vector<int>(m * n + 1, 0);
        for (int i = 0; i <= m * n; i++) {
            fa[i] = i;
        }

        auto pos = [=](int x, int y) {
            return x * n + y;
        };
        const int dx[4] = {1, 0, -1, 0};
        const int dy[4] = {0, -1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if (ni < 0 || nj < 0 || ni >= m || nj >= n) {
                        unionSet(pos(i, j), pos(m - 1, n));
                        continue;
                    }
                    if (board[ni][nj] == 'O') {
                        unionSet(pos(i, j), pos(ni, nj));
                    } 
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                if (find(pos(i, j)) != find(pos(m - 1, n))) {
                    board[i][j] = 'X';
                }
            }
        }
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
