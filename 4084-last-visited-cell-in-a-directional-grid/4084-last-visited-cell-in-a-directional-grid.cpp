class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        vector<vector<bool>>vis(grid.size(), vector<bool>(grid[0].size(),false));
        int r = 0, c = 0, preR = 0, preC = 0;
        while(r < grid.size() && c < grid[0].size() && r >= 0 && c >= 0 && !vis[r][c]){
            char dir = grid[r][c];
            vis[r][c] = true;
            preR = r,preC = c;
            if(dir == 'R') c++;
            else if(dir == 'L') c--;
            else if(dir == 'U') r--;
            else r++;
        }
        return {preR, preC};
    }
};