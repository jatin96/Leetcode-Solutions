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

    void findPath(TreeNode* root,int searchValue, string &currPath, string& finalPath) {
        if (root == NULL)
            return;
        
        if (root -> val == searchValue) {
            finalPath = currPath;
            return;
        }
        
        currPath.push_back('L');
        findPath(root -> left, searchValue,currPath, finalPath);
        currPath.pop_back();
        currPath.push_back('R');
        findPath(root -> right, searchValue, currPath, finalPath);
        currPath.pop_back();
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath = "";
        string endPath = "";
        string currPath = "";
        findPath(root, startValue, currPath, startPath);
        currPath = "";
        findPath(root, destValue, currPath, endPath);
        
        int startLength = startPath.length();
        int endLength = endPath.length();
        
        cout << startPath << endl;
        cout << endPath << endl;
        
        int pos = 0;
        while (pos < startLength && pos < endLength && startPath[pos] == endPath[pos]) pos++;
        
        string res = "";
        for (int i = pos; i < startLength; i++) res.push_back('U');
        
        for (int i = pos; i < endLength; i++) res.push_back(endPath[i]);
        
        return res;
        
        
        
        
    }
};