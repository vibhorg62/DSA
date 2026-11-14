class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int mini = INT_MAX;
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) pref[i + 1] = pref[i] + nums[i];
        for (int i = 0; i < n; i++) {
            for (int len = l; len <= r && i + len <= n; len++) {
                int sum = pref[i + len] - pref[i];
                if (sum > 0)
                    mini = min(mini, sum);
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};