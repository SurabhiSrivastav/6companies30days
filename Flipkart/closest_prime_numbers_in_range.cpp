class Solution {
public:
    vector<int> primes;
    bool isPrime[1000001];
    vector<int> closestPrimes(int left, int right) {
        memset(isPrime, true, sizeof isPrime);
        isPrime[0] = isPrime[1] = 0;
       
        for(int i = 2;i * i <= 1e6;i++){
            if(isPrime[i] == 1){
                for(int j = i * i;j <= 1e6;j += i){
                    isPrime[j] = false;
                }
            }    
        }
        
        for(int i = 2;i <= 1e6;i++){
            if(isPrime[i] && (i >= left && i <= right)){
                primes.push_back(i);
            }
        }
        
        long nums1 = -1e6, nums2 = 1e6;
        
        for(int i = primes.size() - 2;i >= 0;i--){
            if(primes[i + 1] - primes[i] <= nums2 - nums1){
                nums1 = primes[i];
                nums2 = primes[i + 1];
            }
        }
        
        if(primes.size() < 2) return {-1, -1};
        return {(int)nums1, (int)nums2};
    }
};
