class Solution {
public:
    void backtrack(vector<string>& res, string curr, int open, int closed) {
        if (!open && !closed) {
            res.push_back(curr);
            return;
        }
        if (open)
            backtrack(res, curr+'(', open-1, closed+1);
        if (closed)
            backtrack(res, curr+')', open, closed-1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(res, "", n, 0);
        return res;
    }
};