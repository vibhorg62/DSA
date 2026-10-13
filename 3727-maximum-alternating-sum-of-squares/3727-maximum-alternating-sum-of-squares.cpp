class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto &it:nums) it=abs(it);
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0,r=n-1;
        long long sum = 0;
        vector<int>temp;
        int k=0;
        while(l<=r){
            if(k%2==0){
                temp.push_back(nums[r]);
                r--;
            }
            else{
                temp.push_back(nums[l]);
                l++;
            }
            k++;
        }
        for(int i=0;i<temp.size();i++){
            if(i%2==0){
                sum+=temp[i]*temp[i];
            }
            else sum-=temp[i]*temp[i];
        }
        return sum;
    }
};