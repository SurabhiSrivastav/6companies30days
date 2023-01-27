class Solution {
public:
    int give(int num,int n)
    {
        if(num < 0)
            return 0;
        if(num>=n)
            return n-1;
        return num;
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<mat.size();i++)
            for(int j=1;j<mat[0].size();j++)
                mat[i][j]+=mat[i][j-1];
        
        for(int i=0;i<mat[0].size();i++)
            for(int j=1;j<mat.size();j++)
                mat[j][i]+=mat[j-1][i];
        
        vector<vector<int>> ans;        
        for(int i=0;i<mat.size();i++)
        {
            vector<int> v;
            for(int j=0;j<mat[0].size();j++)
            {
                int val = 0;
                val+=mat[give(i+k,n)][give(j+k,m)];
                if(i > k)
                    val-=mat[give(i-k-1,n)][give(j+k,m)];
                if(j > k)
                    val-=mat[give(i+k,n)][give(j-k-1,m)];
                if(i>k and j>k)
                    val+=mat[give(i-k-1,n)][give(j-k-1,m)];
                
                v.push_back(val);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
