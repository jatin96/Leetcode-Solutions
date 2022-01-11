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
    int binaryToDecimal(string binary) {
        int len = binary.length();
        
        int p = 1;
        int num = 0;
        for (int i = len - 1; i >= 0; i--) {
            num += p * (binary[i] - '0');
            p *= 2;
        }
        
        return num;
    }
    void solveIt(TreeNode * root, string &binary) {
        
        if(root -> left == NULL && root -> right == NULL) {
            string newBinary = binary + (root -> val == 0 ? "0" : "1");            
            res += binaryToDecimal(newBinary);
            return;
        }
        
        string newBinary = binary + (root -> val == 0 ? "0" : "1");
        if(root -> left != NULL)
        solveIt(root -> left, newBinary);
        if(root -> right != NULL)
        solveIt(root -> right, newBinary);
    }
    int sumRootToLeaf(TreeNode* root) {
        string binary = "";
        solveIt(root, binary);
        return res;
    }
};