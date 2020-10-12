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
    public boolean isValidBST(TreeNode root) {
        long INF=Long.MAX_VALUE;
        return dfs(root,INF,-INF);
    }
    boolean dfs(TreeNode root, long left, long right){
        if(root == null){ return true; }
        if(root.val >= left || root.val <= right ){ return false; }
        return dfs(root.left, root.val, right) && dfs(root.right,left, root.val);
    }
}
