class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < cards.size(); i++)
        {
            mp[cards[i]].push_back(i);
        }
        int minm = INT_MAX;
        for(auto i : mp)
        {
            auto v = i.second;
            if(v.size() > 1)
            {
                for(int i = 1; i < v.size(); i++)
                {
                    minm = min(minm, v[i] - v[i - 1] + 1);
                }
            }
        }
        return minm == INT_MAX ? -1 : minm;
    }
};
