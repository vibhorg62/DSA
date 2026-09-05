class Solution {
public:
    vector<vector<int>>dp;
    bool solve(string &s1,string &s2,string &s3,int i,int j){
        if(i==0 && j==0) return true;
        if(dp[i][j]!=-1) return dp[i][j];
        bool ans=false;
        if(i>0 && s1[i-1]==s3[i+j-1]){
            ans = ans || solve(s1,s2,s3,i-1,j);
        }
        if(j>0 && s2[j-1]==s3[i+j-1]){
            ans = ans || solve(s1,s2,s3,i,j-1);
        }
        return dp[i][j] = ans;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(n+m !=s3.size()) return false;
        dp=vector<vector<int>>(n+1,vector<int>(m+1,-1));
        dp[0][0]=true;
        return solve(s1,s2,s3,n,m);
    }
};