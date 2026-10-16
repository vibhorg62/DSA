class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char>stk;
        int n = s.size();
        int rem = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') stk.push(s[i]);
            else if(s[i]==')'){
                if(stk.empty()){
                    s.erase(i,1);
                    i--;
                    n--;
                }
                else{
                    stk.pop();
                }
            }
            rem=stk.size();
        }
        for(int i=n-1;i>=0;i--){
            if(rem>0 && s[i]=='(') {
                s.erase(i,1);
                rem--;
            }
        }
        return s;
    }
};