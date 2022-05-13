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
    
    vector<TreeNode*> res;
    unordered_map<string, int> mm;
    string solveIt(TreeNode *root) {
        if (root == NULL) return "#";
        
        string left = solveIt(root -> left);
        string right = solveIt(root -> right);
        
        string serializedString = to_string(root-> val) + "|" + left + "|" + right;
        if(mm[serializedString] == 1) {
            res.push_back(root);
        }
        mm[serializedString]++;
        
        return serializedString;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        solveIt(root);
        return res;
    }
};