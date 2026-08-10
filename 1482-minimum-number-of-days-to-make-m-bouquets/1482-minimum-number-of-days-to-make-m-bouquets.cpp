class Solution {
public:
    bool possible(vector<int>&bloomDay,int m,int k,int i,int bq){
        int cnt=0;
        for(int j=0;j<bloomDay.size();j++){
            if(bloomDay[j]<=i) cnt++;
            else {
                bq+=cnt/k;
                cnt=0;
            }
        }
        bq+=cnt/k;
        if(bq>=m) return true;
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k>bloomDay.size()) return -1;
        int mini=*min_element(bloomDay.begin(),bloomDay.end());
        int maxi=*max_element(bloomDay.begin(),bloomDay.end());
        while(mini<maxi){
            int mid=(mini+maxi)/2;
            if(possible(bloomDay,m,k,mid,0)) maxi=mid;
            else mini=mid+1;
        }
        return mini;
    }
};