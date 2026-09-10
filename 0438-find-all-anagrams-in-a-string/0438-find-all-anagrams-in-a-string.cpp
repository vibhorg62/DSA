class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int right = 0;
        int n = s.size();
        int left = 0;
        map<char,int>window,mpp;
        for(char it:p) mpp[it]++;
        vector<int>arr;
        while(right < n){
            char ch = s[right];
            window[ch]++;
            if(right - left+1 > p.size()){
                char t = s[left]; 
                window[t]--;
                if(window[t]==0) window.erase(t);
                left++;
            }
            if((right-left+1) == p.size() && mpp==window) arr.push_back(left);
            right++;
        }
        return arr;
    }
};