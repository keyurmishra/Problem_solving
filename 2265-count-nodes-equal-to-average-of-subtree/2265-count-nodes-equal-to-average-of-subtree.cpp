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
    int matchingnodes=0;
    pair<int,int>dfs(TreeNode* node){
        if(!node)return {0,0};
        auto[leftsum,leftcount]=dfs(node->left);
        auto[rightsum,rightcount]=dfs(node->right);
        int currsum=leftsum+rightsum+node->val;
        int currcount=leftcount+rightcount+1;
        if(currsum / currcount == node->val){
            matchingnodes++;
        }
        return {currsum,currcount};

    }
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingnodes;
        
    }
};