class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>arr;
        priority_queue<pair<int,int>>pq;
        int left=0;
        for(int right=0;right<n;right++){
            pq.push({nums[right],right});
            if(right-left+1 > k) left++;
            while(!pq.empty() && pq.top().second<left) pq.pop();
            if(right-left+1 == k) arr.push_back(pq.top().first);
        }
        return arr;
    }
};