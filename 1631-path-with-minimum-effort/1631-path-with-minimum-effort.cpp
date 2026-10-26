class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n+1,vector<int>(m+1,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int dx[] = {0,0,1,-1};
        int dy[] = {1,-1,0,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int d=it.first;
            int i=it.second.first;
            int j=it.second.second;
            if(d>dist[i][j]) continue;
            if(i==n-1 && j==m-1) return d;
            for(int k=0;k<4;k++){
                int x = i+dx[k];
                int y = j+dy[k];
                if(x>=0 && y>=0 && x<n && y<m){
                    int effort = max(d,abs(heights[i][j]-heights[x][y]));
                    if(effort<dist[x][y]){
                        dist[x][y]=effort;
                        pq.push({effort,{x,y}});
                    }
                }
            }
        }
        return 0;
    }
};