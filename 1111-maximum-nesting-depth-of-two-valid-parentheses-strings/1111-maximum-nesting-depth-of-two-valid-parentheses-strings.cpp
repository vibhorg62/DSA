class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        int bal=0;
        vector<int>ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') bal++;
            ans.push_back(bal%2);
            if(s[i]==')') bal--;
        }
        return ans;
    }
};