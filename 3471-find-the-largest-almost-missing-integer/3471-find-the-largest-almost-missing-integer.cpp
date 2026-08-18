class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mpp;
        int ans=-1;
        int n=nums.size();
        if(k==1){
            for(int i=0;i<n;i++) mpp[nums[i]]++;
            for(auto it:mpp) {
                if(it.second==1) ans=max(ans,it.first);
            }
            return ans;
        }
        else if(k>1 && k<n){
            for(int i=0;i<n;i++) mpp[nums[i]]++;
            if(mpp[nums[0]]==1) ans=max(ans,nums[0]);
            if(mpp[nums[n-1]]==1) ans=max(ans,nums[n-1]);
            return ans;
        }
        else {
            return *max_element(nums.begin(),nums.end());
        }
    }
};