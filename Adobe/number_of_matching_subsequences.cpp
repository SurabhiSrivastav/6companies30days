class Solution {
public:
    int res = 0;
    
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> map(26, vector<int>());
        for(int i = 0 ; i < s.size() ; ++i)
            map[s[i] - 'a'].push_back(i);
        
        for(auto& word : words) {
            int ind = -1;
            for(int i = 0 ; i < word.size() ; ++i) {
                vector<int>& v = map[word[i] - 'a'];
                int tempInd = lower_bound(v.begin(), v.end(), ind + 1) - v.begin();
                if(tempInd >= v.size()) {
                    ind = -1;
                    break;
                }
                
                ind = v[tempInd];
            }
            if(ind != -1)
                ++res;
        }
        return res;
    }
};
