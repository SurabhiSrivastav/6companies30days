class Solution {
public:
       void solve(string s, string temp, int count, vector<string>& ans)
    {
        if(s.length() <= 0 && count == 4)
        {
            temp.pop_back(); 
            ans.push_back(temp); 
            return; 
        }
        for(int i = 0; i < s.length(); i++)
        {
            string FirstHalf = s.substr(0, i + 1); 
            if(FirstHalf[0] == '0' && FirstHalf.length() > 1)
                return;           
            if(stol(FirstHalf) <= 255)
            {
                string LastPart = s.substr(i + 1); 
                solve(LastPart, temp + FirstHalf + '.', count + 1, ans);
            }
            else 
            {
                return; 
            }
        }
    }   
    vector<string> restoreIpAddresses(string s) {
        int n = s.size(); 
        if(n < 4) 
        return {};
        vector<string> ans; 
        string temp = ""; 
        solve(s, temp, 0, ans); 
        return ans; 
    }
};
