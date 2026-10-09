class Solution {
public:
    int minSwaps(string s) {
        int cnt=0;
        stack<int>stk;
        for(int i=0;i<s.size();i++){
            if(s[i]=='[') stk.push(s[i]);
            else{
                if(!stk.empty()) stk.pop();
                else cnt++;
            }
        }
        if(cnt%2==1) return cnt/2 +1;
        return cnt/2;
    }
};