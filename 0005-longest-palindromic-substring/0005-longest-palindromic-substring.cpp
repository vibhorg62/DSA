class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() < 2) return s;
        
        int maxStart = 0, maxLen = 1;
        
        // Expand around center approach
        // Time: O(n^2), Space: O(1)
        for (int i = 0; i < s.length(); i++) {
            // Odd-length palindromes
            int left = i, right = i;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    maxStart = left;
                }
                left--;
                right++;
            }
            
            // Even-length palindromes
            left = i;
            right = i + 1;
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                int len = right - left + 1;
                if (len > maxLen) {
                    maxLen = len;
                    maxStart = left;
                }
                left--;
                right++;
            }
        }
        
        return s.substr(maxStart, maxLen);
    }
};