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
    class Path {
        int val;
        int length;
        Path() {
            val = 0;
            length = 0;
        }
        
        Path(int val, int length) {
            this.val = val;
            this.length = length;
        }
    }
    int res = 1;
    private Path longestPath(TreeNode root) {
        if (root == null)
            return new Path();
        
        Path p = longestPath(root.left);
        Path q = longestPath(root.right);
        int val = root.val;
        
        if (p.val == q.val && q.val == val){
            res = Math.max(res, p.length + q.length + 1);
            return new Path(val, 1 + Math.max(p.length, q.length));
        }
        else if (p.val == val) {
            res = Math.max(res, p.length + 1);
            return new Path(val, p.length + 1);
        }
        else if (q.val == val) {
            res = Math.max(res, q.length + 1);
            return new Path(val, q.length + 1);
        }
        
        res = Math.max(res, 1);
        return new Path(val, 1); 
    }
    public int longestUnivaluePath(TreeNode root) {
        longestPath(root);
        return res - 1;
    }
}