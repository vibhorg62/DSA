class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),[](string &a,string &b){
            return a.size()<b.size();
        });
        int  n=words.size();
        unordered_map<string,int>dp;
        int ans=1;
        for(string s:words){
            dp[s]=1;
            for(int j=0;j<s.size();j++){
                string p=s.substr(0,j)+s.substr(j+1);
                if(dp.find(p)!=dp.end()){
                    dp[s]=max(dp[s],dp[p]+1);
                }
            }
            ans=max(ans,dp[s]);
        }
        return ans;
    }
};