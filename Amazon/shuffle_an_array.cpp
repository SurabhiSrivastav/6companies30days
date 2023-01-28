class Solution {
private:
    vector<int> temp;    
public:
    Solution(vector<int>& nums) {
        temp = nums;        
    }
    vector<int> reset() {
        return temp;
    }
    vector<int> shuffle() {
        vector <int> temp_2;
        temp_2 = temp;
        
        for(int i = 0;i < temp_2.size();i++){
            int index = rand() % (i+1);
            swap(temp_2[i],temp_2[index]);
        }
        return temp_2;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
 
