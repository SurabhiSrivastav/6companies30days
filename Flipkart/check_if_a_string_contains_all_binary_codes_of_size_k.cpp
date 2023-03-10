class Solution {
public:
    bool hasAllCodes(string s, int k) { 
       int n = s.length();
        if(n<k){
            return false;
        }
       unordered_set<string>str;
        for(int i=0;i<n-k+1;i++){
            str.insert(s.substr(i,k));
        }
      return (str.size() == pow(2,k));
    }
};
