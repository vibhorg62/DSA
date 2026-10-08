class Solution {
public:
    bool check(int mid,vector<int>&nums,int threshold){
        int n=nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            if(nums[i]%mid==0) sum+=nums[i]/mid;
            else sum+=(nums[i]/mid)+1;
        }
        if(sum<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<high){
            int mid = low+(high-low)/2;
            if(check(mid,nums,threshold)) high = mid;
            else low = mid+1;
        }
        return low;
    }
};