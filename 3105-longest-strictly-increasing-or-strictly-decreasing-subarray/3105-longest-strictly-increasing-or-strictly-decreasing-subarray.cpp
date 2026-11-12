class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                cnt1++;
            }
            else{
                ans=max(ans,cnt1+1);
                cnt1=0;
            }
        }
        ans=max(ans,cnt1+1);
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                cnt2++;
            }
            else{
                ans=max(ans,cnt2+1);
                cnt2=0;
            }
        }
        ans=max(ans,cnt2+1);
        return ans;
    }
};