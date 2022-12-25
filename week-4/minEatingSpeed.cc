class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1, right = 0;
        for (const auto &p : piles) {
            right += p;
        }
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (validate(piles, h, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool validate(vector<int>& piles, int h, long long k) {
        int cost_h = 0;
        for (const auto &p : piles) {
            cost_h += (p + k - 1) / k;
        }
        return cost_h <= h;
    }
};
