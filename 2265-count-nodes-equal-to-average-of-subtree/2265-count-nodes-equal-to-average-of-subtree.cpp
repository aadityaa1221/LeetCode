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
    int f(TreeNode *root){
        if(!root) return 0;

        int sum = 0, cnt = 0;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            sum += node->val;
            cnt++;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        int avg = sum / cnt;
        return avg;
    }
    int averageOfSubtree(TreeNode* root) {
        if(!root) return 0;

        int cnt = 0;
        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();

            if(node->val == f(node)) cnt++;

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        return cnt;
    }
};