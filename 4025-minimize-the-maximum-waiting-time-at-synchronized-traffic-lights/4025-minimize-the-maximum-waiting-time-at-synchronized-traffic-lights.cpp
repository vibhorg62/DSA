class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& a) {
        int maxl=*max_element(lights.begin(),lights.end());
        int ans=0;
        for(int i=0;i<a.size();i++){
            if(a[i]%period>=maxl) ans=max(ans,period-(a[i]%period));
        }
        return ans;
    }
};