class Solution {
public:
    int rev(int x)
    {
        int w=0;
        while(x!=0)
        {
            w=w*10+x%10;
            x/=10;
        }
        return w;
    }
    int countNicePairs(vector<int>& nums) {
      for(int i=0;i<nums.size();i++)
      {
          nums[i]=nums[i]-rev(nums[i]);
      }
      map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
        }
        long long s=0;
        for(auto it:m)
        {
        long long n=it.second;
        if(n!=1)
        s+=n*(n-1)/2;
        }
        int inif=1e9+7;
        return s%inif;
    }
};
