class Solution {
public:
    const int MOD = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>bitCount(31,0);
        for(int x:nums){
            for(int i=0;i<31;i++){
                if(x>>i & 1) bitCount[i]++;
            }
        }
        long long sum=0;
        for(int i=0;i<k;i++){
            long long curr=0;
            for(int j=0;j<31;j++){
                if(bitCount[j]>0){
                    curr|=(1<<j);
                    bitCount[j]--;
                }
            }
            sum=(sum+(curr*curr)%MOD)%MOD;
        }
        return sum;
    }
};