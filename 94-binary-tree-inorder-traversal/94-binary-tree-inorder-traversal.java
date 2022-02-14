/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    List<Integer> res = new ArrayList<>();
    private void inorderTraversalUtil(TreeNode root) {
        if (root == null)
            return;
        inorderTraversalUtil(root.left);
        res.add(root.val);
        inorderTraversalUtil(root.right);
    } 
    public List<Integer> inorderTraversal(TreeNode root) {
        inorderTraversalUtil(root);
        return res;
    }
}