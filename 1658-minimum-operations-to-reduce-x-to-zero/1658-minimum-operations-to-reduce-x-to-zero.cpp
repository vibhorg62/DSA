class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (int num : nums) total += num;

        int target = total - x;
        if (target < 0) return -1;         
        if (target == 0) return nums.size();

        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0, maxLen = -1;

        while (j < n) {
            sum += nums[j];

            while (sum > target && i <= j) {
                sum -= nums[i];
                i++;
            }

            if (sum == target) {
                maxLen = max(maxLen, j - i + 1);
            }

            j++;
        }

        return (maxLen == -1) ? -1 : (n - maxLen);
    }
};
