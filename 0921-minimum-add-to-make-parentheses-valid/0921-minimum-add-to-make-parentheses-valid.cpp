class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int n=s.size();
        stack<int>stk;
        for(int i=0;i<n;i++){
            if(s[i]=='(') stk.push(s[i]);
            else{
                if(!stk.empty()){
                    stk.pop();
                }
                else{
                    cnt++;
                }
            }
        }
        return cnt+stk.size();
    }
};