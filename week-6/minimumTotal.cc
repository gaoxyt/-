class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> f(n, vector<int>());

        f[0].push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (j == 0) {
                    f[i].push_back(f[i - 1][j] + triangle[i][j]);
                    continue;
                }
                if (j == triangle[i].size() - 1) {
                    f[i].push_back(f[i - 1][j - 1] + triangle[i][j]);
                    continue;
                }
                int tmp = min(f[i - 1][j - 1], f[i - 1][j]) + triangle[i][j];
                f[i].push_back(tmp);
            }
        }
        int ans = f[n - 1][0];
        for (int i = 1; i < f[n - 1].size(); i++) {
            ans = min(ans, f[n - 1][i]);
        }
        return ans;
    }
};
