class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector <vector<pair<int, int>>> neighs(n+1);       
        for(auto t: times)                                 
            neighs[t[0]].push_back({t[1], t[2]});
            
        vector <int> res(n+1, INT_MAX);                    
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;    
        pq.push({0, k});                                   
        res[k]=0;                                          

        while(!pq.empty()){
            int vertex=pq.top().second;     
            pq.pop();
            
            for(auto neigh:neighs[vertex]){                
                if(res[vertex]+neigh.second<res[neigh.first]){  
                    res[neigh.first]=res[vertex]+neigh.second;
                    pq.push({res[neigh.first], neigh.first});
                }
            }
        }
        int ans=*max_element(res.begin()+1, res.end());     
        return ans==INT_MAX?-1:ans;                         
    }
};
