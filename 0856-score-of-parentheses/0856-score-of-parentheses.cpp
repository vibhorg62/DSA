class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int>stk;
        int score=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                stk.push(score);
                score=0;
            }
            else{
                int prev = stk.top();
                stk.pop();
                if(score==0) score+=1;
                else score*=2;
                score+=prev;
            }
        }
        return score;
    }
};