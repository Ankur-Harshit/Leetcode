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
    bool solve(TreeNode* root){
        // base case //
        if(root == NULL) return false;
        // if(root->left== NULL && root->right== NULL){
        //     if(root->val == 1) return true;
        //     delete(root);
        //     return false;
        // }
        bool left = solve(root->left);
        bool right = solve(root->right);

        if(!left){
            root->left = NULL;
            delete(root->left); 
        }
        if(!right){
            root->right = NULL;
            delete(root->right);
        }
        return(left || right || (root->val == 1));
    }
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (root == NULL) return NULL;
        bool ans = solve(root);
        // agar root node se false aa rha hai mtlab root node ka
        // left me bhi khi 1 nhi hai and right me bhi one nhi hai
        // and root node khud bhi 0 hai tabhi aisa hoga to uske 
        // liye sab delete krna hoga and NULL return hoga //
        if(ans == false) return NULL;
        return root;
    }
};
