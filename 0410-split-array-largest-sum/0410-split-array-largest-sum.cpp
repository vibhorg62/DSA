class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int high = 0;
        for(int i=0;i<n;i++){
            high+=nums[i];
        }
        int low = *max_element(nums.begin(),nums.end());
        while(low<high){
            int mid = low+(high-low)/2;
            int parts = 1,sum = 0;
            for(int i=0;i<n;i++){
                if(sum+nums[i]>mid){
                    parts++;
                    sum=nums[i];
                }
                else sum+=nums[i];
            }
            if(parts<=k) high = mid;
            else low = mid+1;
        }
        return low;
    }
};