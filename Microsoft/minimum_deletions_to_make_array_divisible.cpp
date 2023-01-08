class Solution {
	public:
     int helper(int a, int b) {
		if (b == 0)
			return a;
		return helper(b, a % b);
	}
     int minOperations(vector<int>&arr, vector<int>&numsDivide) 
     {
		int gcd = numsDivide[0];
		for (int i = 0; i < numsDivide.size(); i++) {
			gcd = helper(numsDivide[i], gcd);
		}
		sort(arr.begin(),arr.end());
		int count = 0;
		for (int i = 0; i < arr.size(); i++) {
			if (gcd % arr[i] == 0) {
				return count;
			} else {
				count += 1;
			}
		}
		return -1;
	}
};
