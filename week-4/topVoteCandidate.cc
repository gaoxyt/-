class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        map<int, deque<int>> votes;
        map<int, int> person_vote;
        for (int i = 0; i < persons.size(); i++) {
            if (person_vote.count(persons[i]) == 0) {
                person_vote[persons[i]] = 1;
                votes[1].push_front(persons[i]);
            } else {
                auto &v = person_vote.at(persons[i]);
                //votes[v].erase(persons[i]);
                v += 1;
                votes[v].push_front(persons[i]);
            }
            times_.push_back(times[i]);
            auto it = --votes.end();
            t_to_p_[times[i]] = it->second.front();
            //cout << "time:" << times[i] << ", " << it->second.front() << endl;
        }
    }
    
    int q(int t) {
        int left = 0, right = times_.size() - 1;
        while (left < right) {
            int mid = left + (right - left + 1) / 2;
            if (times_[mid] <= t) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        //cout << right << " ";
        return t_to_p_[times_[right]];
    }

private:
    vector<int> times_;
    map<int, int> t_to_p_;
};
