class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int cnt=0;
        map<int,int>mpp;
        sort(arr2.begin(),arr2.end());
        for(int i=0;i<arr2.size();i++) mpp[arr2[i]]=i;
        for(int i=0;i<arr1.size();i++){
            auto it = lower_bound(arr2.begin(),arr2.end(),arr1[i]-d);
            if(it == arr2.end() || *it > arr1[i]+d){
                cnt++;
            }
        }
        return cnt;
    }
};