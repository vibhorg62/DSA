class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<vector<char>>&grid,int i,int j,int bal){
        int n=grid.size();
        int m=grid[0].size();
        if(i==n || j==m) return 0;
        if(i==n-1 && j==m-1) return bal==1;
        if(dp[i][j][bal]!=-1) return dp[i][j][bal];
        int nb=bal;
        if(grid[i][j]=='(') nb++;
        else nb--;
        if(nb<0) return 0;
        return dp[i][j][bal] = solve(grid,i+1,j,nb) || solve(grid,i,j+1,nb);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        dp=vector<vector<vector<int>>>(n,vector<vector<int>>(m,vector<int>(m+n+1,-1)));
        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;
        return solve(grid,0,0,0);
    }
};