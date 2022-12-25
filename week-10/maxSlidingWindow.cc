class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            num_mp_[nums[i]] = i;
            auto it = --num_mp_.end();
            while (it->second <= i - k) {
                num_mp_.erase(it);
                it = --num_mp_.end();
            }
            if (i >= k - 1) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }

private:
    map<int, int> num_mp_;
};
