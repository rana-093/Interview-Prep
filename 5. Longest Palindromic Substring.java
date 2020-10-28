//RANA
class Solution {
  
  int[][] dp = new int[1005][1005];
  
  public String longestPalindrome(String s) {
      s = "#" + s;
      for(int i = 1; i < s.length(); i++){ dp[i][i] = 1; }
      
      for(int len = 2; len < s.length(); len++){
          for(int i = 1; (i+len - 1)  < s.length(); i++){
              int j = i + len - 1;
              if(len == 2) {
            	  dp[i][j] = (s.charAt(i)==s.charAt(j)) ? 1 : 0;
              }
              else {
            	  int res = 0;
            	  if( (s.charAt(i) == s.charAt(j)) && (dp[i+1][j-1] == 1) ) {
            		  dp[i][j] = 1;
            	  }
            	  else { dp[i][j] = 0; }
              }
          }
      }
      
      int len = 0;
      int idx1 = 0 , idx2 = 0;
      for(int i = 1 ; i < s.length(); i++) {
    	  for(int j = i; j < s.length(); j++) {
    		  int l = j - i + 1;
    		  if(dp[i][j] == 0) { continue; }
    		  if(l > len) { len = l; idx1 = i ; idx2 = j; }
    	  }
      }
//      System.out.println(len+" , "+idx1+" , "+idx2);
      return s.substring(idx1, idx2 + 1);
  }
}
