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
    TreeNode* build(int start, int end,  vector<int> &inorder, vector<int> &postorder,int &idx, unordered_map<int, int> &mp){
        if(start>end){
            return NULL;
        }
        int rootval = postorder[idx];
        int mid = mp[postorder[idx++]];
        TreeNode* root = new TreeNode(rootval);
        root->right = build(mid+1, end, inorder, postorder, idx, mp);
        root->left = build(start, mid-1, inorder, postorder, idx, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        reverse(postorder.begin(), postorder.end());
        unordered_map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int idx=0;
        return build(0, inorder.size()-1, inorder, postorder, idx, mp);
    }
};