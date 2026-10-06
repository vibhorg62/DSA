class Solution {
public:
    vector<vector<int>>vis;
    int ans=0;
    int total=0;
    void solve(int i,int j,vector<vector<int>>&grid,int cnt){
        int n=grid.size();
        int m=grid[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || grid[i][j]==-1) return ;
        vis[i][j]=1;
        if(grid[i][j]==2){
            if(cnt==total) ans++;
            vis[i][j]=0;
            return;
        }
        solve(i+1,j,grid,cnt+1);
        solve(i-1,j,grid,cnt+1);
        solve(i,j+1,grid,cnt+1);
        solve(i,j-1,grid,cnt+1);
        vis[i][j]=0;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vis = vector<vector<int>>(n,vector<int>(m,0));
        int x=0,y=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=-1) total++;
                if(grid[i][j]==1) {
                    x=i;
                    y=j;
                }
            }
        }
        solve(x,y,grid,1);
        return ans;
    }
};