class Solution {
    bool canGo(int i, int j, vector<vector<int>>& grid, int& t, vector<vector<bool>>& vis, int& n) {
        if(i < 0 || j < 0 || i >= n || j >= n || grid[i][j] > t || vis[i][j]) {
            return false;
        }
        vis[i][j] = true;
        if(i == n-1 && j == n-1) {
            return true;
        }
        return canGo(i+1, j, grid, t, vis, n) || 
            canGo(i, j+1, grid, t, vis, n) ||
            canGo(i-1, j, grid, t, vis, n) ||
            canGo(i, j-1, grid, t, vis, n);
    }
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = INT_MAX;
        int left = 0;
        int right = n*n;
        while(left <= right) {
            vector<vector<bool>> vis(n, vector<bool> (n, false));
            int mid = left + (right - left)/2;
            if(canGo(0, 0, grid, mid, vis, n)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};
