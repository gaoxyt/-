class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        fa = vector<int>(n + 1, 0);
        for (int i = 1; i < n; i++) {
            fa[i] = i;
        }

        vector<int> ans(2, 0);
        for (int i = 0; i < edges.size(); i++) {
            const auto &edge = edges[i];
            if (find(edge[0]) == find(edge[1])) {
                ans[0] = edge[0];
                ans[1] = edge[1];
            }
            unionSet(edge[0], edge[1]);
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
