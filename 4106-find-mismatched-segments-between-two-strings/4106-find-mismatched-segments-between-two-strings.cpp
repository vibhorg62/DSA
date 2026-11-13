class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>sp;
        int n=s1.size();
        int l1=0,l2=0;
        string res1="";
        string res2="";
        while(l1<n && l2<n){
            if(s1[l1]!=s2[l2]){
                res1+=s1[l1];
                res2+=s2[l2];
                l1++;
                l2++;
            }
            else{
                if(!res1.empty() && !res2.empty()) sp.push_back({res1,res2});
                res1="";
                res2="";
                l1++;
                l2++;
            }
        }
        if(!res1.empty() && !res2.empty()) sp.push_back({res1,res2});
        return sp;
    }
};