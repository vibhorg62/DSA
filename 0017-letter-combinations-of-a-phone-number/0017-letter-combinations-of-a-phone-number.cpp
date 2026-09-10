class Solution {
public:
    vector<string>res;
    map<int,string>mpp;
    void solve(string &digits,int i,string &curr,int n){
        if(i==n){
            res.push_back(curr);
            return;
        }
        string s = mpp[digits[i]-'0'];
        for(char ch:s){
            curr+=ch;
            solve(digits,i+1,curr,n);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
       mpp[2] = "abc";
       mpp[3] = "def";
       mpp[4] = "ghi";
       mpp[5] = "jkl";
       mpp[6] = "mno";
       mpp[7] = "pqrs";
       mpp[8] = "tuv";
       mpp[9] = "wxyz";
       int n = digits.size();
       if(n==0) return {};
       string curr = "";
       solve(digits,0,curr,n);
       return res;
    }
};