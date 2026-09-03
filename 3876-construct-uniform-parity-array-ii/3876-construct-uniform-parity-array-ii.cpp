class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        vector<int>temp=nums1;
        sort(temp.begin(),temp.end());
        int oc=0;
        int smo=INT_MAX;
        for(auto it:temp){
            if(it%2==1){
                oc+=1;
                smo=min(smo,it);
            }
        }
        if(oc==0) return true;
        for(auto it:temp){
            if(it%2==0){
                if(smo>=it) return false;
            }
        }
        return true;
    }
};