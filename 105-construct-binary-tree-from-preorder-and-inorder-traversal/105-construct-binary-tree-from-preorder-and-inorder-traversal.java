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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        
        if (inorder == null || preorder == null || inorder.length != preorder.length)
            return null;
        
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        for (int i = 0; i < inorder.length; i++)
            hm.put(inorder[i], i);
        
        return buildTreeUtil(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, hm);
    }
    
    private TreeNode buildTreeUtil(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd, HashMap<Integer, Integer> hm) {
        
        if (preStart > preEnd || inStart > inEnd)
            return null;
        
        TreeNode root = new TreeNode(preorder[preStart]);
        int rootIndex = hm.get(preorder[preStart]);
        
        int numLeft = rootIndex - inStart;
        int numRight = inEnd - rootIndex;
        
        root.left = buildTreeUtil(preorder, preStart + 1, preStart + numLeft, inorder, inStart, rootIndex - 1, hm);
        root.right = buildTreeUtil(preorder, preEnd - numRight + 1, preEnd, inorder, rootIndex + 1, inEnd, hm);
        return root;
    }
}