class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        unordered_map<int, vector<int>> adj;

        for(auto it:r){
            adj[it[0]].push_back(it[1]);
        }

        int cnt=(n-adj.size())*2;

        for(auto &[row,it]:adj){
            sort(it.begin(),it.end());

            bool l=true,m=true,rr=true;

            for(auto x:it){
                if(x>=2 && x<=5) l=false;
                if(x>=4 && x<=7) m=false;
                if(x>=6 && x<=9) rr=false;
            }
            if(l && rr)
                cnt+=2;
            else if(l || m || rr)
                cnt++;
        }

        return cnt;
    }
};