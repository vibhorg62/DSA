class Solution {
public:
    vector<vector<vector<int>>>dp;
    int ans = 0;
    int solve(int i,int cnt_m,int cnt_n,vector<string>&strs,int m,int n){
        int sz = strs.size();
        if(i>=sz || cnt_m>m || cnt_n>n) return 0;
        if(dp[i][cnt_n][cnt_m]!=-1) return dp[i][cnt_n][cnt_m];
        int curr_m=0;
        int curr_n=0;
        for(int j=0;j<strs[i].size();j++){
            if(strs[i][j]=='0') curr_m++;
            else curr_n++;
        }
        int take = 0;
        if(curr_m+cnt_m <=m && curr_n+cnt_n <=n) {
            take = 1+solve(i+1,cnt_m+curr_m,cnt_n+curr_n,strs,m,n);
        }
        int not_take = solve(i+1,cnt_m,cnt_n,strs,m,n);
        return dp[i][cnt_n][cnt_m] = max(take,not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int sz=strs.size();
        dp=vector<vector<vector<int>>>(sz+1,vector<vector<int>>(n+1 ,vector<int>(m+1,-1)));
        return solve(0,0,0,strs,m,n);
    }
};