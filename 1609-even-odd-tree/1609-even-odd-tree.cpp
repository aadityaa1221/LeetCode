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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q;
        q.push(root);
        int l = 0;
        while(!q.empty()){
            int size = q.size();
            int m =1;
            stack<int> st;
            if(l%2==0){
                m--;
            }
            if(m==0){
                for(int i = 0; i < size; i++ ){
                    TreeNode * t = q.front();
                    q.pop();
                    if(t->val%2==0){
                        return false;
                    }
                    else if(!st.empty() && st.top()>=t->val){
                        return false;
                    }
                    st.push(t->val);
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
            }
            else{
                 for(int i = 0; i < size; i++ ){
                    TreeNode * t = q.front();
                    q.pop();
                    if(t->val%2!=0){
                        return false;
                    }
                    else if(!st.empty() && st.top() <= t->val){
                        return false;
                    }
                    st.push(t->val);
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
            }
            l++;
        }
        return true;
    }
};