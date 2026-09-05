class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int>suffmin(nums.size()+1,0);
        vector<int>premax(nums.size()+1,0);
        int n=nums.size();
        premax[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            premax[i]=max(nums[i],premax[i-1]);
        }
        suffmin[n-1]=nums[n-1];
        for(int i=nums.size()-2;i>=0;i--){
            suffmin[i]=min(nums[i],suffmin[i+1]);
        }
        int ans=INT_MAX,ind=-1;
        for(int i=0;i<nums.size();i++){
            int ins=premax[i]-suffmin[i];
            if(ins<ans && ins<=k){
                ans=ins;
                ind=i;
                return ind;
            }
        }
        return -1;
    }
};