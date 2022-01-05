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
    unordered_map<int, vector<TreeNode *>> dp;
    vector<TreeNode *> solveIt(int n) {
        vector<TreeNode *> res;
        if (n == 1) {
            TreeNode *node = new TreeNode();
            res.push_back(node);
            return res;
        }
        
        if(n % 2 == 0) {
            return res;
        }
        
        if(dp.find(n) != dp.end())
            return dp[n];
        
        int x = n - 1;
        
        for (int i = 1; i <= x; i += 2) {
            auto left = solveIt(i);
            auto right = solveIt(x - i);
            
            for (auto lf : left) {
                for (auto rh: right) {
                    TreeNode *root = new TreeNode();
                    root -> left = lf;
                    root -> right = rh;
                    res.push_back(root);
                }
            }
            
        }
        
        return dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return solveIt(n);
    }
};