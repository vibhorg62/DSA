class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int l=0,r=0;
        int n=nums.size();
        multiset<int>low,high;
        vector<double>ans;
        while(r<n){
            if(low.empty() || nums[r]<=*low.rbegin()){
                low.insert(nums[r]);
            }
            else high.insert(nums[r]);
            while(low.size()>high.size()+1){
                int x=*low.rbegin();
                high.insert(x);
                low.erase(low.find(x));
            }
            while(low.size()<high.size()){
                int x=*high.begin();
                low.insert(x);
                high.erase(high.find(x));
            }
            if(r-l+1==k){
                if(low.size()==high.size()){
                    int x = *low.rbegin();
                    int y = *high.begin();
                    double res = ((double)x+y)/2.0;
                    ans.push_back(res);
                }
                else if(low.size()>high.size()){
                    ans.push_back(double(*low.rbegin()));
                }
                else ans.push_back(double(*high.begin()));
                if(high.count(nums[l])) high.erase(high.find(nums[l]));
                else low.erase(low.find(nums[l]));
                l++;
                while(low.size()>high.size()+1){
                    int x=*low.rbegin();
                    high.insert(x);
                    low.erase(low.find(x));
                }
                while(low.size()<high.size()){
                    int x=*high.begin();
                    low.insert(x);
                    high.erase(high.find(x));
                }
            }
            r++;
        }
        return ans;
    }
};