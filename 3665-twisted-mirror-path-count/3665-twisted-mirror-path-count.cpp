class Solution {
public:
    vector<vector<int>>dp;
    int LEFT=0;
    int UP=1;
    const int MOD=1e9+7;
    int solve(int i,int j,vector<vector<int>>&grid,int cameFrom){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m || i<0 ||j<0) return 0;
        if(i==n-1 && j==m-1) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(grid[i][j]==1){
            if(cameFrom==LEFT) return solve(i+1,j,grid,UP);
            else return solve(i,j+1,grid,LEFT);
        }
        return dp[i][j] = (solve(i+1,j,grid,UP)+solve(i,j+1,grid,LEFT))%MOD;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        return solve(0,0,grid,0);
    }
};