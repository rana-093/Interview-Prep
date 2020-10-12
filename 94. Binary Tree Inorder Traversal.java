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
    public List<Integer> inorderTraversal(TreeNode root) {
        List< Integer > temp = new ArrayList<>()  ;
        Stack< TreeNode > S = new Stack<>();
        TreeNode cur = root;
        while(!S.isEmpty() || cur!=null){
            while(cur!=null){
                S.push(cur);
                cur = cur.left;
            }
            cur = S.pop();
            temp.add(cur.val);
            cur = cur.right;
        }
        return temp;
    }
}

