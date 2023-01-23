class Solution {
public:
    string customSortString(string order, string str) {
        string ans;
        unordered_map<char, int>mp;

        for(int i = 0; i < str.size(); i++) 
            mp[str[i]]++;
        
        for(int i = 0; i < order.size(); i++)
            while(mp[order[i]] > 0){
                ans.push_back(order[i]);
                mp[order[i]]--;
            }
        
        for(auto it : mp)
            while(it.second > 0){
                ans.push_back(it.first);
                it.second--;
            }   
     return ans;
    }
};
