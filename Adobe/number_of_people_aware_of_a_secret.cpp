class Solution {
public:
    int peopleAwareOfSecret(int n, int d, int f) {
        int mod = 1e9 + 7;
        vector<long long> know(n), share(n), forget(n);
        
        know[0] = 1;
        for(int i=d;i < f and i < n;i++) share[i]++;
        if(f < n) forget[f]++;
        
        for(int i=1;i<n;i++){
            know[i] = ((know[i-1] - forget[i] + mod) % mod);
            know[i] = (know[i] + share[i]) % mod;
            
            for(int j=i+d;j < i+f and j < n;j++) 
                share[j] = (share[j] + share[i]) % mod;
            
            if(i+f < n) forget[i+f] = (forget[i+f] + share[i]) % mod;
        }
        
        return know[n-1];
    }
};
