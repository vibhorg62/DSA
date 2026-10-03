class Solution {
public:
    int longestValidParentheses(string s) {
        // stack<int> stk;
        // stk.push(-1);
        // int ans = 0;
        // for(int i = 0; i < s.size(); i++) {
        //     if(s[i] == '(') {
        //         stk.push(i);
        //     } else {
        //         stk.pop();
        //         if(stk.empty()) {
        //             stk.push(i);
        //         } else {
        //             ans = max(ans, i - stk.top());
        //         }
        //     }
        // }
        // return ans;
        int n=s.size();
        int ans=0;
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            if(s[i]==')'){
                if(s[i-1] == '('){
                    if(i>=2) dp[i]=dp[i-2]+2;
                    else dp[i]=2;   
                }
                else{
                    int j=i-dp[i-1]-1;
                    if(j>=0 && s[j]=='('){
                        dp[i]=dp[i-1]+2;
                        if(j-1>=0) dp[i]+=dp[j-1];
                    }
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};