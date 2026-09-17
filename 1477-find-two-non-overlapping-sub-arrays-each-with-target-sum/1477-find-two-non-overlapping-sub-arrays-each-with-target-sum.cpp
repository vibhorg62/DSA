class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = n+1;
        vector<int>minLen(n,INF);
        int l = 0;
        long long sum = 0;
        int best = INF;
        int ans = INF;
        for(int r = 0; r<n ; r++){
            sum+=arr[r];
            while(sum>target){
                sum-=arr[l];
                l++;
            }
            if(sum==target){
                int len = r-l+1;
                if(l>0 && minLen[l-1]!=INF){
                    ans = min(ans,len+minLen[l-1]);
                }
                best = min(best,len);
            }
            minLen[r]=best;
        }
        return ans ==INF ?-1:ans;
    }
};