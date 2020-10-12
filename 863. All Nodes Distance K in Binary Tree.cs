/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */

  public class Solution {     
        Dictionary< TreeNode, TreeNode > Par = new Dictionary< TreeNode, TreeNode>();
        void dfs(TreeNode root, TreeNode par){
            if(root == null){ return ; }
            Par.Add(root, par);
            dfs(root.left, root);
            dfs(root.right, root);
            
        }
        
        public IList<int> DistanceK(TreeNode root, TreeNode target, int K) {
            int []dist = new int[10005];
            var ans = new List< int > ();
            dfs(root, null);
            for(int i = 0; i < 10000; i++){ dist[i] = 0; }
            Queue< KeyValuePair< TreeNode, int> > Q = new Queue< KeyValuePair< TreeNode, int> >();
            Q.Enqueue(new KeyValuePair<TreeNode, int>(target,0));
            HashSet< TreeNode > vis = new HashSet<TreeNode>();
            dist[target.val] = 0;
//            Console.WriteLine("val: "+target.val);
            vis.Add(target);
            while(Q.Count!=0){
                KeyValuePair< TreeNode, int > top = Q.Dequeue();
                TreeNode temp = top.Key;
                int lvl = top.Value;
                if(temp.left!=null && !vis.Contains(temp.left)){
                    dist[temp.left.val] = dist[temp.val] + 1;
                    Q.Enqueue(new KeyValuePair<TreeNode, int>(temp.left, lvl+1));
                    vis.Add(temp.left);
                }
                if(temp.right!=null && !vis.Contains(temp.right)){
                    dist[temp.right.val] = dist[temp.val] + 1;
                    Q.Enqueue(new KeyValuePair<TreeNode, int>(temp.right, lvl+1));
                    vis.Add(temp.right);
                }
                TreeNode p = Par[ temp ];
                if(!vis.Contains(p) && p!=null){
                    vis.Add(p);
                    dist[p.val] = dist[temp.val] + 1;
                    Q.Enqueue(new KeyValuePair<TreeNode, int>(p, dist[p.val]));
                }
            }
            for(int i = 0; i < Par.Count; i++){
                Console.WriteLine(i+" , "+dist[i]);
                if(dist[i] == K){
                    ans.Add(i);
                }   
            }
            return ans;
        }
    }
