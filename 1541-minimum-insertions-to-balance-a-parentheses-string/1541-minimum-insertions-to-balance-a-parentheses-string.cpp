class Solution {
public:
    int minInsertions(string s) {
        stack<char>stk;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') {
                stk.push(s[i]);
            }
            else{
                if(i+1<n && s[i+1]==')'){
                    i++;
                }
                else ans++;
                if(!stk.empty()) stk.pop();
                else ans++;
            }
        }
        return ans + 2*stk.size();
    }
};