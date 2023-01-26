class Solution {
public:
    int totalFruit(vector<int>& fruits) { 
        unordered_map<int,int> mp;
        int mx = 0;
        int i=0,j=0, n=fruits.size();
        for(;j<n; j++)
        {
            mp[fruits[j]]++;
            while(mp.size()>2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                mp.erase(fruits[i]);
                i++;
            }
            mx= max(mx,j-i+1);
        }
        return mx;
    }
};
