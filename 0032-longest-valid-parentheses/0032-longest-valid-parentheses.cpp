class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<char, int>> st; 
        int i = 0, n = s.size(), ans = 0;
        while(i < n) {
            if(!st.empty() && st.top().first == '(' && s[i] == ')') {
                st.pop();
                if(st.empty()) ans = max(ans, i + 1);
                else ans = max(ans, i - st.top().second);
            }
            else st.push({s[i], i}); i++;
        }
        return ans;
    }
};