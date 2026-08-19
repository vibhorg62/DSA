class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.size();
        int m = station.size();
        vector<int> pre(n), suf(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (station[j] != skill[i])
                j++;
            pre[i] = j;
            j++;
        }
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[j] != skill[i])
                j--;
            suf[i] = j;
            j--;
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, suf[i] - pre[i - 1]);
        }

        return ans;
    }
};