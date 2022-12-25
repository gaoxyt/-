class Solution {
public:
    int climbStairs(int n) {
        vector<int> f(n + 1, 0);
        for (int i = n; i >= 0; i--) {
            if (i == n) {
                f[i] = 0;
            } else if (i == n - 1) {
                f[i] = 1;
            } else if (i == n - 2) {
                f[i] = 2;
            } else {
                f[i] = f[i + 1] + f[i + 2];
            }
        }
        return f[0];
    }
};
