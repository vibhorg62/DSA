class Solution {
public:
    vector<vector<vector<int>>>dp;
    int MOD = 1e9+7;
    int solve(vector<int>&group,vector<int>&profit,int n,int minProfit,int members,int i,int curr_p){
        if(i==group.size()) return curr_p>=minProfit;
        if(dp[i][members][curr_p]!=-1) return dp[i][members][curr_p];
        int take = 0;
        int new_p = min(minProfit,curr_p+profit[i]);
        if(members + group[i] <=n) take = solve(group,profit,n,minProfit,members+group[i],i+1,new_p);
        int not_take = solve(group,profit,n,minProfit,members,i+1,curr_p);
        return dp[i][members][curr_p] = (take+not_take)%MOD;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sz = group.size();
        dp=vector<vector<vector<int>>>(sz+1,vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
        return solve(group,profit,n,minProfit,0,0,0);
    }
};