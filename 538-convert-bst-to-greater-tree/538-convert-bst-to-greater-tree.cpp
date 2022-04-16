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
    void solveIt(TreeNode * root, int &currSum) {
        if (root == NULL)
            return;
        
        solveIt(root -> right, currSum);
        currSum += root -> val;
        root -> val = currSum;
        solveIt(root -> left, currSum);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int currSum = 0;
        solveIt(root, currSum);
        
        return root;
    }
};