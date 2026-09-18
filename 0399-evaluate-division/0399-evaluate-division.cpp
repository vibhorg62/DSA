class Solution {
public:
    bool dfs(string &src,string &dest,unordered_map<string,vector<pair<string,double>>>&graph,unordered_set<string>&vis,double &ans){
        if(src==dest) return true;
        vis.insert(src);
        for(auto it:graph[src]){
            string next = it.first;
            double val = it.second;
            if(vis.count(next)) continue;
            if(dfs(next,dest,graph,vis,ans)){
                ans*=val;
                return true;
            }
        }
        return false;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>graph;
        for(int i=0;i<equations.size();i++){
            string a = equations[i][0];
            string b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b,val});
            graph[b].push_back({a,1.0/val});
        }
        vector<double>res;
        for(auto it:queries){
            string src = it[0];
            string dest = it[1];
            if(!graph.count(src) || !graph.count(dest)){
                res.push_back(-1.0);
                continue;
            }
            unordered_set<string>vis;
            double ans = 1.0;
            if(dfs(src,dest,graph,vis,ans)) res.push_back(ans);
            else res.push_back(-1.0);
        }
        return res;
    }
};