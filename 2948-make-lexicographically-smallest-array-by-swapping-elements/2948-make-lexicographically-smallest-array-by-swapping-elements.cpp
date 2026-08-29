class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<pair<int,int>>sp;
        for(int i=0;i<n;i++) sp.push_back({nums[i],i});
        sort(sp.begin(),sp.end());
        for(int i=0;i<n;){
            int j=i;
            while(j+1<n && sp[j+1].first - sp[j].first<=limit) j++;
            vector<int>index,vals;
            for(int k=i;k<=j;k++){
                index.push_back(sp[k].second);
                vals.push_back(sp[k].first);
            }
            sort(index.begin(),index.end());
            for(int k=0;k<vals.size();k++){
                nums[index[k]] = vals[k];
            }
            i=j+1;
        }
        return nums;
    }
};