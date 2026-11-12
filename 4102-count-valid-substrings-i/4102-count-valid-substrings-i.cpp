class Solution {
public:
    long long countValidSubstrings(string s) {
        long long ans = 0;
        int n = s.size();
        int i = 0;
        for(int j = 0; j < n; j++) {
            if(j >= 2 && s[j-2] == 'a' && s[j-1] == 'b' && s[j] == 'c') i = j-1;
            ans += (j-i+1);
        }
        return ans;
    }
};