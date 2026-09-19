class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        unordered_map<char,int>mpp;
        int ans = 0;
        while(r<s.size()){
            mpp[s[r]]++;
            while(mpp[s[r]]>1){
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};