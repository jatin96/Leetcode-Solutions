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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> nodesQueue;
        vector<vector<int>> res;
        if (root == NULL)
            return res;
        
        nodesQueue.push(root);
        bool leftToRight = true;
        while (!nodesQueue.empty()) {
            int siz = nodesQueue.size();
            
            vector<int> row(siz);
            for (int i = 0; i < siz; i++) {
                TreeNode *node = nodesQueue.front();
                nodesQueue.pop();
                
                int pos = leftToRight ? i : siz - 1 - i;
                
                row[pos] = node -> val;
                
                if (node -> left)
                    nodesQueue.push(node -> left);
                
                if (node -> right) 
                    nodesQueue.push(node -> right);
            }
            
            res.push_back(row);
            leftToRight = !leftToRight;
        }
        
        return res;
    }
};