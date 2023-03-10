class Solution {
public:
    bool bobdfs(int n, vector<int> node[], vector<int>& amount, vector<bool>& visited, vector<int>& steps, int count){
        if(n == 0){
            steps[0] = count+1;
            return true;
        }
        count++;
        steps[n] = count;

        bool t = false;
        for(int i=0; i<node[n].size(); i++){
            if(!visited[node[n][i]]){
                visited[n] = 1;
                t = t || bobdfs(node[n][i], node, amount, visited, steps, count);
                visited[n] = 0;
            }
        }
        if(!t){
            steps[n] = -1;
        }
        return t;
    }
    
    int alicedfs(int n, vector<int> node[], vector<int>& amount, vector<bool>& visited, vector<int>& steps, int count){
        count++;
        int reward = amount[n];
        if(steps[n] != -1){
            if(count < steps[n]){
                reward = amount[n];
            }
            else if(steps[n] == count){
                reward = amount[n]/2;
            }
            else{
                reward = 0;
            }
        }
        // cout << n << ":" << reward << endl;

        int ans = INT_MIN;
        for(int i=0; i<node[n].size(); i++){
            if(!visited[node[n][i]]){
                visited[n] = 1;
                ans = max(ans, alicedfs(node[n][i], node, amount, visited, steps, count));
                visited[n] = 0;
            }
        }
        if(ans == INT_MIN){
            return reward;
        }
        return ans+reward;
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = 0;
        for(auto &i:edges){
            n = max(i[0],n);
            n = max(i[1], n);
        }

        vector<int> node[n+1];
        for(auto &i:edges){
            node[i[0]].push_back(i[1]);
            node[i[1]].push_back(i[0]);
        }

        vector<int> steps(n+1, -1);
        vector<bool> visited(n+1, 0);

        bobdfs(bob, node, amount, visited, steps, 0);

        for(int i=0; i<visited.size(); i++){
            visited[i] = 0;
        }
        
        return alicedfs(0, node, amount, visited, steps, 0);
    }
};
