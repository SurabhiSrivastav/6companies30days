class Solution {
public:
    bool isSubstring(vector<int> v)
    {
         return (v[0] >= 1 && v[1] >= 1 && v[2] >= 1);
    }
    
    int numberOfSubstrings(string s) 
    {
        int total = 0;
        vector<int> counts(3,0);
        int n = s.length();
        int i = 0;
        int j = 0;
        
        while (j < s.length()) {
            counts[s[j] - 'a']++;
            if (!isSubstring(counts)) {
                j++;
            }
            else {
                while (isSubstring(counts)) {
                    total += (n - j);
                    counts[s[i] - 'a']--;
                    i++;
                }
                j++;
            }
        }
        return total;
    }
};
