    class Solution {
    public:
        vector<string>curr;
        vector<vector<string>>res;
        bool check(int row,int col){
            int l=row-1;
            while(l>=0){
                if(curr[l][col]=='Q') return false;
                l--;
            }
            l=row-1;
            int r=col-1;
            while(r>=0 && l>=0) {
                if(curr[l][r]=='Q') return false;
                r--;
                l--;
            }
            l=row-1;
            r=col+1;
            while(l>=0 && r<=curr.size()-1){
                if(curr[l][r]=='Q') return false;
                l--;
                r++;
            }
            return true;
        }
        void solve(int row){
            if(row>=curr.size()){
                res.push_back(curr);
                return;
            }
            for(int col=0;col<curr.size();col++){
                if(check(row,col)) {   
                    curr[row][col] = 'Q';
                    solve(row+1);
                    curr[row][col]='.'; 
                }
            }
        }
        int totalNQueens(int n) {
            curr=vector<string>(n,string(n,'.'));
            solve(0);
            return res.size();
        }
    };