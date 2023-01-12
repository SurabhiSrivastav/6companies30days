class Solution {
public:
    #define ll long long
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        ll n=capital.size();
        priority_queue<ll>pq;
        vector<pair<ll,ll>>container;
        for(ll i=0;i<n;i++){
            container.push_back({capital[i],profits[i]});
        }
        sort(container.begin(),container.end());
        ll i=0;
        while(k--){
            while(container[i].first<=w && i<n){
                pq.push(container[i++].second);
            }
            if(!pq.empty()){
                w+=pq.top();pq.pop();
            }
        }
        return w;
    }
    
};
