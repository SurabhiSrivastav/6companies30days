int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(auto e : edges){
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(i == j){
                        dist[i][j] = 0;
                        continue;
                    }
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = 0, minCount = n; int id = 0;
        for(auto d : dist){
            auto v = d; int count = 0;
            for(auto u : v){
                if(u <= distanceThreshold) count++;
            }
            if(minCount >= count){
                minCount = count;
                res = id;
            }
            id++;
        }
        return res;
    }
