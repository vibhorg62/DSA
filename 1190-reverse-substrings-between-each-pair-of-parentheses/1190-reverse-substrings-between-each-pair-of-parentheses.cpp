class Solution {
public:
    string reverseParentheses(string s) {
        stack<string>stk;
        int n=s.size();
        string curr;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                stk.push(curr);
                curr="";
            }
            else if(s[i]==')'){
                reverse(curr.begin(),curr.end());
                string temp=stk.top();
                stk.pop();
                curr=temp+curr;
            }
            else{
                curr+=s[i];
            }
        }
        return curr;
    }
};