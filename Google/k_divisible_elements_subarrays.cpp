class Solution {
public:
    int countDistinct(vector<int>& arr, int k, int p) {
        int n = arr.size();
        set<string> st;
        for(int i=0;i<n;i++){
            string s;
            int count = 0;
            for(int j=i;j<n;j++){
                if(arr[j] % p == 0) count++;
                if(count > k) break;
                s.push_back(arr[j]+'0');
                s.push_back('.');
                st.insert(s);
            }
        }
        return st.size();
    }
};
