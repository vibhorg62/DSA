/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<int,int>mpp;
    vector<int>arr;
    void solve(TreeNode* root){
        if(root==NULL) return ;
        solve(root->left);
        arr.push_back(root->val);
        mpp[root->val]++;
        solve(root->right);
    }
    bool findTarget(TreeNode* root, int k) {
        solve(root);
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<i;j++){
                if(arr[i]+arr[j]==k) return true;
            }
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]+arr[j]==k) return true;
            }
        }
        return false;
    }
};