class Solution {
public:
    set<pair<int,int>>st;
    int dfs(vector<int>&vis,vector<vector<int>>&adj,int node,int &cnt){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(st.count({node,it})) cnt++;
                dfs(vis,adj,it,cnt);
            }
        }
        return cnt;
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n+1);
        for(int i=0;i<connections.size();i++){
            int u=connections[i][0];
            int v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            st.insert({u,v});
        }
        int c=0;
        vector<int>vis(n,0);
        dfs(vis,adj,0,c);
        return c;
    }
};