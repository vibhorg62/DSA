class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(vector<int>&nums , int k,int i,int prev){
        if(i>=nums.size()) return 0;
        if(dp[i][k][prev]!=-1) return dp[i][k][prev];
        int pick=0;
        int notpick=solve(nums,k,i+1,prev);
        if(prev==nums.size() || nums[i]==nums[prev]){
            pick=1+solve(nums,k,i+1,i);
        }
        else if(k>0){
            pick=1+solve(nums,k-1,i+1,i);
        }
        return dp[i][k][prev]=max(pick,notpick);
    }
    int maximumLength(vector<int>& nums, int k) {
        dp=vector<vector<vector<int>>>(nums.size(),vector<vector<int>>(k+1,vector<int>(nums.size()+1,-1)));
        return solve(nums,k,0,nums.size());
    }
};