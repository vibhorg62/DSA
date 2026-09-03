class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int>need,window;
        for(char it:t) need[it]++;
        int n=s.size();
        int left=0;
        int minLen=INT_MAX;
        int cnt=0;
        int start=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            window[s[right]]++;
            if(need.count(ch) && window[ch]<=need[ch]) cnt++;
            while(cnt==t.size()){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start=left;
                }
                char r=s[left];
                if(need.count(r) && window[r]<=need[r]) cnt--;
                window[s[left]]--;
                left++;
            }
        }
        if(minLen==INT_MAX) return "";
        return s.substr(start,minLen);
    }
};