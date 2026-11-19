class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n <= 3) return 0;
        int d1 = nums[n - 3] - nums[0];
        int d2 = nums[n - 1] - nums[2];
        int d3 = nums[n - 2] - nums[1];
        return min({d1, d2, d3});
    }
};