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
    int res = 0;
    vector<int> solveIt(TreeNode * root, int targetSum) {
        vector<int> tmp;
        if (root == NULL)
            return tmp;
        
        vector<int> p = solveIt(root -> left, targetSum);
        vector<int> q = solveIt(root -> right, targetSum);
        int val = root -> val;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] + val == targetSum)
                res++;
            
            tmp.push_back(p[i] + val);
        }
        
        for (int i = 0; i < q.size(); i++) {
            if (q[i] + val == targetSum)
                res++;
            
            tmp.push_back(q[i] + val);
        }
        
        if (val == targetSum)
            res++;
        
        tmp.push_back(val);
        
        return tmp;
            
    }
    int pathSum(TreeNode* root, int targetSum) {
        solveIt(root, targetSum);
        
        return res;
    }
};