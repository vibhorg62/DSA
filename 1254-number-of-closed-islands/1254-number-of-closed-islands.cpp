class Solution {
public:
    void solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j]==1) return;
        vis[i][j]=1;
        solve(i+1,j,grid,vis);
        solve(i,j+1,grid,vis);
        solve(i-1,j,grid,vis); 
        solve(i,j-1,grid,vis);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        int ans=0;
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) solve(i,0,grid,vis);
            if(grid[i][m-1]==0) solve(i,m-1,grid,vis);
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==0) solve(0,j,grid,vis);
            if(grid[n-1][j]==0) solve(n-1,j,grid,vis);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    solve(i,j,grid,vis);
                    ans++;
                }
            }
        }
        return ans;
    }
};