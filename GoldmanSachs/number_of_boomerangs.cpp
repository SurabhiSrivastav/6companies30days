class Solution {
public:
    int dist(vector<int> v1, vector<int> v2){
        return pow((v1[0]-v2[0]),2)+pow((v1[1]-v2[1]),2);
    }
    
    int numberOfBoomerangs(vector<vector<int>>& p) {
        int ans = 0;
        for (int i=0; i<p.size(); i++){
            unordered_map<int,int> mp;
            for (int j=0; j<p.size(); j++){
                mp[dist(p[i],p[j])]++;
            }
            for (auto it: mp){
                if (it.second==2){
                    ans++;
                }
                else if (it.second>2){
                    int t = it.second;
                    ans+= (t*(t-1))/2;
                }
            }
        }
        return ans*2;
    }
};
