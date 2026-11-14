class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        int ans = INT_MAX;
        for(int len=l;len<=r;len++){
            int left=0,right=0; 
            int sum=0;
            while(right<n){
                sum+=nums[right];
                while(right-left+1>len){
                    sum-=nums[left];
                    left++;
                }
                if(right-left+1==len && sum>0) ans=min(ans,sum);
                right++;
            }
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};