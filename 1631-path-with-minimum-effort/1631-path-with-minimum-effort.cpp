class Solution {
public:
    bool dfs(int i,int j,vector<vector<int>>&heights,int mid,vector<vector<int>>&vis){
        int n=heights.size();
        int m=heights[0].size();
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]) return 0;
        if(i==n-1 && j==m-1) return 1;
        vis[i][j]=1;
        if(i<n-1 && abs(heights[i+1][j]-heights[i][j])<=mid) if(dfs(i+1,j,heights,mid,vis)) return 1;
        if(j<m-1 && abs(heights[i][j+1]-heights[i][j])<=mid) if(dfs(i,j+1,heights,mid,vis)) return 1;
        if(i>0 && abs(heights[i-1][j]-heights[i][j])<=mid) if(dfs(i-1,j,heights,mid,vis)) return 1;
        if(j>0 && abs(heights[i][j-1]-heights[i][j])<=mid) if(dfs(i,j-1,heights,mid,vis)) return 1;
        return 0;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0;
        int high = 1e6;
        int n=heights.size();
        int m=heights[0].size();
        int ans=0;
        while(low<=high){
            int mid = low+(high-low)/2;
            vector<vector<int>>vis(n+1,vector<int>(m+1,0));
            if(dfs(0,0,heights,mid,vis)){
                ans=mid;
                high=mid-1;
            }
            else low=mid+1;
        }      
        return ans;
    }
};