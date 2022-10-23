class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        for (const auto &domain : cpdomains) {
            auto space_index = domain.find(' ');
            int cnt = atoi(domain.substr(0, space_index).c_str());
            auto dm = domain.substr(space_index + 1);
            domains_cnt_[dm] += cnt;
            auto pos = dm.rfind('.');
            while (pos != string::npos) {
                string d1 = dm.substr(pos + 1);
                domains_cnt_[d1] += cnt;
                pos = dm.rfind('.', pos - 1);
            }
        }
        vector<string> ans;
        for (const auto &dc : domains_cnt_) {
            string a = to_string(dc.second) + " " + dc.first;
            ans.emplace_back(a);
        }
        return ans;
    }
private:
    unordered_map<string, int> domains_cnt_;
};

