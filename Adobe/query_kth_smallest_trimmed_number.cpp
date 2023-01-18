class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
        vector<int> ans;
        int size = nums[0].size();
        int qsize = q.size();
        for(int i = 0;i<qsize;i++){
            int q1 = q[i][0];
            int q2 = q[i][1];
            priority_queue<pair<string,int>> pq;
            for(int j = 0;j<nums.size();j++){
                pq.push({(nums[j].substr(size - q2,q2)),j});
                if(pq.size() > q1)
                    pq.pop();
            }
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};
