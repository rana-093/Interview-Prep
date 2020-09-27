import java.util.*;
import java.io.*;

class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> S = new Stack<Integer>();
        int ans = 0;
        int prev = 0;
        S.push(-1);
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c=='('){
                S.push(i);
            }
            else{
                S.pop();
                if(S.size() > 0){
                    int cur = i - S.peek();
                    ans = Math.max(ans,cur);
                }
                else{
                    S.push(i);
                }
            }
        }
        return ans;
    }
}
