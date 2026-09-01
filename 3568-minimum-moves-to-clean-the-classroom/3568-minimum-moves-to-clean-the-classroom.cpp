class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int n=classroom.size();
        int m=classroom[0].size();
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        int str=-1,stc=-1;
        int lc=0;
        map<pair<int,int>,int>mpp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j]=='S'){
                    str=i;
                    stc=j;
                }
                else if(classroom[i][j]=='L'){
                    mpp[{i,j}] = lc;
                    lc++;
                }
            }
        }
        if(lc==0) return 0;
        int target_mask = (1<<lc)-1;
        vector<vector<vector<vector<int>>>>dist(n,vector<vector<vector<int>>>(m,vector<vector<int>>(energy+1,vector<int>(target_mask+1,-1))));
        queue<tuple<int,int,int,int>>q;
        dist[str][stc][energy][0]=0;
        q.push({str,stc,energy,0});
        while(!q.empty()){
            auto [r,c,c_en,vis_mask]=q.front();
            q.pop();
            int moves=dist[r][c][c_en][vis_mask];
            if(vis_mask==target_mask) return moves;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<m && classroom[nr][nc]!='X' && c_en>0){
                    int next_moves=moves+1;
                    int n_en=c_en-1;
                    int next_mask=vis_mask;
                    if(classroom[nr][nc]=='L') {
                        next_mask |= (1<<mpp[{nr,nc}]);
                    }
                    else if(classroom[nr][nc]=='R') n_en=energy;
                    
                    if(dist[nr][nc][n_en][next_mask]==-1){
                        dist[nr][nc][n_en][next_mask]=next_moves;
                        q.push({nr,nc,n_en,next_mask});
                    }
                }
            }
        }
        return -1;
    }
};