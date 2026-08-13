class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pref(n);
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pref[i]=sum;
        }
        int maxi=*max_element(nums.begin(),nums.end());
        while(maxi<sum){
            int mid=maxi+(sum-maxi)/2;
            int parts=1;
            int curr=0;
            for(int x:nums){
                if(curr+x<=mid) curr+=x;
                else {
                    parts++;
                    curr=x;
                }
            }
            if(parts<=k) sum=mid;
            else maxi=mid+1;
        }
        return maxi;
    }
};