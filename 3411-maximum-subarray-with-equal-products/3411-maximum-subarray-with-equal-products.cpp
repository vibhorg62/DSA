class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            long long pr=nums[i];
            long long lc=nums[i];
            long long gc=nums[i];
            for(int j=i;j<n;j++){
                if(j>i){
                    if(pr > LLONG_MAX / nums[j]) break;
                    pr*=nums[j];
                    lc=lcm((long long)nums[j],lc);
                    gc=gcd((long long)nums[j],gc);
                    if(lc > LLONG_MAX / gc) break;
                }
                if(pr==(lc*gc)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};