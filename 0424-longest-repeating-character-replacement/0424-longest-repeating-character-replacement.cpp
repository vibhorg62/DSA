class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mpp;
        int l=0,ans=0;
        for(int r=0;r<s.size();r++){
            mpp[s[r]]++;
            int mx=0;
            for(auto it:mpp){
                mx=max(mx,it.second);
            }
            while((r-l+1)-mx>k){
                mpp[s[l]]--;
                l++;
                mx=0;
                for(auto it:mpp) mx=max(mx,it.second);
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};