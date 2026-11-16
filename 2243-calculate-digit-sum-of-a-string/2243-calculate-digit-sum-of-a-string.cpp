class Solution {
public:
    string solve(string &s,int k){
        string fin="";
        int n=s.size();
        for(int i=0;i<s.size();i+=k){
            int ans=0;
            for(int j=i;j<i+k && j<n;j++){
                ans+=s[j]-'0';
            }
            fin+=to_string(ans);
        }
        return fin;
    }
    string digitSum(string s, int k) {
        while(s.size()>k){
            s=solve(s,k);
        }
        return s;
    }
};