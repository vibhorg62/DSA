class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n=nums.size();
        int idx=0;
        for(int i=n-1;i>=1;i--){
            if(target[i]>target[i-1]){
                idx=i;
                break;
            }
        }
        int fd = n-1;
        for(int i=0;i<n;i++){
            if(nums[i]!=target[i]){
                fd=i;
                break;
            }
        }
        if(fd<idx) return 0;
        unordered_map<int,int>mpp1;
        unordered_map<int,int>mpp2;
        for(int i=fd;i<n;i++){
            mpp1[nums[i]]++;
            mpp2[target[i]]++;
        }
        if(mpp1!=mpp2) return 0;
        return fd-idx+1;
    }
};