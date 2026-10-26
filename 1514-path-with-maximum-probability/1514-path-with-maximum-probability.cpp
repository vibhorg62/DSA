class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dist(n+1,0);
        priority_queue<pair<double,int>>pq;
        vector<vector<pair<int,double>>>adj(n+1);
        int k=0;
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            double sp = succProb[k];
            adj[u].push_back({v,sp});
            adj[v].push_back({u,sp});
            k++;
        }
        dist[start_node]=1;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double d = it.first;
            int u = it.second;
            if(d<dist[u]) continue;
            for(auto edge:adj[u]){
                int v =  edge.first;
                double w = edge.second;
                if(d*w>dist[v]){
                    dist[v]=d*w;
                    pq.push({dist[v],v});
                }
            }
        }
        return dist[end_node];
    }
};