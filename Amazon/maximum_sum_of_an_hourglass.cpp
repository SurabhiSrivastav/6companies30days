class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        int mSum = 0;
        int prefix[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j==0){
                    prefix[i][j] = grid[i][j];
                }
                else{
                    prefix[i][j] = prefix[i][j-1] + grid[i][j];
                }
            }
        }
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                int curSum = 0;
                curSum += (prefix[i][j+2] + prefix[i+1][j+1]-prefix[i+1][j]+prefix[i+2][j+2]);
    
                if(j>=1){
                    curSum -= (prefix[i][j-1] + prefix[i+2][j-1]);
                }
                mSum = max(curSum, mSum);
            }
        }
        return mSum;
    }
};
