class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int l_len = left.size();
        int r_len = right.size();
        
        int l = 0;
        int r = 0;
        
        if (l_len > 0) {
            l = left[0];
            for (int i = 1; i < l_len; i++) {
                l = max(l, left[i]);
            }
        }
        
        if (r_len > 0) {
            r = right[0];
            for (int i = 1; i < r_len; i++) {
                r = min(r, right[i]);
            }
        }
        
        if (l_len == 0 and r_len == 0)
            return 0;
        else if (l_len == 0)
            return n - r;
        else if (r_len == 0)
            return l;
        return max(l, n - r);
    }
};
