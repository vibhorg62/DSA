class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int e=1,o=0,ans=0,sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum%2==0){
                ans=(ans+o)%MOD;
                e++;
            }
            else{
                ans=(ans+e)%MOD;
                o++;
            }
        }
        return ans%MOD;
    }
};