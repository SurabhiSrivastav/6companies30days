class Solution {
    priority_queue<int> maxHeap;
public:
    void solve(vector<vector<int>>& grid,int i,int j,int ii,int jj,int res){
        int x=ii,y=jj,n=grid.size(),m=grid[0].size();
        
        while(y!=j && x+1<n ){
            x++;
            y++;
            res+=grid[x][y];
        }
        if(y!=j && x+1==n) return;
        
        while(x!=ii && y+1<m){
            x--;
            y++;
            res+=grid[x][y];
        }
        if(x!=ii && y+1==m) return;
        
        while(x-1!=i){
            x--;
            y--;
            res+=grid[x][y];
        }
        
        maxHeap.push(res);
        
        return;
    }
    
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                maxHeap.push(grid[i][j]);
                
                int jj=j,ii=i,sum=grid[i][j];
                while(jj-1>=0 && ii+1<n){
                    jj--;
                    ii++;
                    sum+=grid[ii][jj];
                    solve(grid,i,j,ii,jj,sum);
                }
            }
        }
        
        set<int> s;
        vector<int> res;
        while(!maxHeap.empty() && s.size()!=3){
            int curr=maxHeap.top();
            if(s.find(curr)==s.end()){
                s.insert(curr);
                res.push_back(curr);
            }
            maxHeap.pop();
        }
        
        return res;
    }
};
