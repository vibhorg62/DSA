class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            if(i==0 && n>1){
                if(nums[i]>=nums[i+1]) cnt++;
            }
            if(i==n-1 && n>1){
                if(nums[i]>=nums[i-1]) cnt++;
            }
            if(i>0 && i<n-1){
                double avg = ((double)nums[i-1] + (double)nums[i+1])/2;
                if(double(nums[i])>=avg) cnt++;
            }
        }
        return cnt;
    }
};