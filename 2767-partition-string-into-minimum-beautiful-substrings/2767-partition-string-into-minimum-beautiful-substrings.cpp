class Solution {
public:
    int solve(string &s,int i,vector<int>&dp){
        int n=s.size();
        if(i==n) return 0;
        if(s[i]=='0') return 10000;
        if(dp[i]!=-1) return dp[i];
        int ans = 10000;
        long long num = 0;
        for(int j=i;j<n;j++){
            num = num*2 + (s[j]-'0');
            long long x = num;
            while(x>1 && x%5==0){
                x=x/5;
            }
            if(x==1) ans = min(ans,1+solve(s,j+1,dp));
        }
        return dp[i]=ans;
    }
    int minimumBeautifulSubstrings(string s) {
        int n=s.size();
        vector<int>dp(n+1,-1);
        int res = solve(s,0,dp);
        if(res==10000) return -1;
        return res;
    }
};