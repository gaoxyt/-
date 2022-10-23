class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        for (int index = 0; index < nums.size(); index++) {
            auto n = nums[index];
            if (ele_details_.count(n) == 0) {
                ele_details_.emplace(n, EleDetail(index));
                continue;
            }
            ele_details_.at(n).Update(index);
        }
        int ans = INT32_MAX;
        int max_d = 0;
        for (const auto &ele : ele_details_) {
            int ele_d = ele.second.cnt;
            int ele_l = ele.second.last_index - ele.second.first_index + 1;
            if (ele_d > max_d) {
                ans = ele_l;
                max_d = ele_d;
            } else if (ele_d == max_d && ele_l < ans) {
                ans = ele_l;
            }
        }
        return ans;
    }

private:
    struct EleDetail{
        EleDetail(int first) : first_index(first), last_index(first), cnt(1) {}
        void Update(int last) {
            last_index = last;
            cnt++;
        }
        int first_index;
        int last_index;
        int cnt;
    };
    unordered_map<int, EleDetail> ele_details_;
};
