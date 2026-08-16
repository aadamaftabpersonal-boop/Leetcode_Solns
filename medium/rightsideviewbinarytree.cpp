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
    vector<int> rightSideView(TreeNode* root){
        if(root==nullptr)return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<int> result;
        while(!q.empty()){
            vector<int> level;
            int size = q.size();
            for(int i=0;i<size;i++){
                level.push_back(q.front()->val);
                if(q.front()->left)q.push(q.front()->left);
                if(q.front()->right)q.push(q.front()->right);
                q.pop();
            }
            result.push_back(level[level.size()-1]);
        }
        return result;
    }
};