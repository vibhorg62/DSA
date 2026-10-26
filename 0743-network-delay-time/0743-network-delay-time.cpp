class Solution {
public:
    const int INF = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        vector<int>dist(n+1,INF);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int d=it.first;
            int u=it.second;
            if(d>dist[u]) continue;
            for(auto edge:adj[u]){
                int v=edge.first;
                int w=edge.second;
                if(d+w < dist[v]){
                    dist[v] = d+w;
                    pq.push({dist[v],v});
                }
            }                               
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INF) return -1;
            ans=max(ans,dist[i]);
        }
        return ans;
    }
};