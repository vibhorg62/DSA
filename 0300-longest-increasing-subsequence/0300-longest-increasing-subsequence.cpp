class Solution {
public:
    vector<vector<int>>dp;
    int len=1;
    int solve(int i,vector<int>&nums,int prev){
        if(i>=nums.size()) return 0;
        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int notTake=solve(i+1,nums,prev);
        int take=0;
        if(prev==-1 || nums[i]>nums[prev]) take=1+solve(i+1,nums,i);
        return dp[i][prev+1]=max(take,notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        dp=vector<vector<int>>(n,vector<int>(n,-1));
        int prev=-1;
        return solve(0,nums,prev);
    }
};