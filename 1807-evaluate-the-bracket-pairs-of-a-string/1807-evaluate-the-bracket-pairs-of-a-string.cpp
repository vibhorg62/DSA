class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mpp;
        int n=s.size();
        for(int i=0;i<knowledge.size();i++) mpp[knowledge[i][0]] = knowledge[i][1];
        string res;
        int i=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                string ch;
                while(s[i]!=')'){
                    ch+=s[i];
                    i++;
                }
                if(mpp.find(ch)!=mpp.end()){
                    res+=mpp[ch];
                }
                else {
                    res+='?';
                }
                i++;
            }
            else {
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};