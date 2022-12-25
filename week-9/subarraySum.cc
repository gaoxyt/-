class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> sum_map;
        sum_map[0] = 1;
        int pre_sum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            pre_sum += nums[i];
            auto it = sum_map.find(pre_sum - k);
            if (it != sum_map.end()) {
                ans += it->second;
            }
            sum_map[pre_sum]++;
        }

        return ans;
    }
};
