class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> bonus(n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0)
                    bonus[i]++;
            }
        }
        vector<int> dp(budget + 1, 0);
        for (int i = 0; i < n; i++) {
            int cost = items[i][1];
            vector<int> ndp = dp;
            for (int b = budget; b >= cost; b--) {
                ndp[b] = max(ndp[b],
                             dp[b - cost] + 1 + bonus[i]);
            }
            for (int b = cost; b <= budget; b++) {
                ndp[b] = max(ndp[b],
                             ndp[b - cost] + 1);
            }
            dp = ndp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};