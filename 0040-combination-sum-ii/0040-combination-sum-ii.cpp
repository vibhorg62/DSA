class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>& candidates , int target,int start,int sum,vector<int>&res){
        if(sum==target){
            ans.push_back(res);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start && candidates[i]==candidates[i-1]) continue;
            if(sum+candidates[i]>target) break;
            res.push_back(candidates[i]);
            solve(candidates,target,i+1,sum+candidates[i],res);
            res.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>res;
        solve(candidates,target,0,0,res);
        return ans;
    }
};