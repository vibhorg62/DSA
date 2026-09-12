class Solution {
public:
    vector<vector<int>>res;
    void solve(int i , vector<int>&curr,int n,int k,vector<int>&arr,int sum){
        if(sum==n && curr.size()==k){
            res.push_back(curr);
            return;
        }
        if(i>=arr.size() || sum>n || curr.size()>k) return;
        curr.push_back(arr[i]);
        solve(i+1,curr,n,k,arr,sum+arr[i]);
        curr.pop_back();
        solve(i+1,curr,n,k,arr,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr={1,2,3,4,5,6,7,8,9};
        vector<int>curr;
        solve(0,curr,n,k,arr,0);
        return res;
    }
};