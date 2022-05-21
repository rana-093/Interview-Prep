class Solution {

    int[] count(String str) {
        int[] res = new int[2];
        for (int i = 0; i < str.length(); i++) {
            res[str.charAt(i) - '0']++;
        }
        return res;
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];
        for (int[] a : dp) Arrays.fill(a, 0);
        for (String str : strs) {
            int[] res = count(str);
            int[][] dp2 = new int[m + 1][n + 1];
            for (int j = 0; j <= m; j++) { // 0
                for (int k = 0; k <= n; k++) { // 1
                    dp2[j][k] = Math.max(dp2[j][k], dp[j][k]);
                    if (j - res[0] >= 0 && k - res[1] >= 0) {
                        dp2[j][k] = Math.max(dp2[j][k], 1 + dp[j - res[0]][k - res[1]]);
                    }
                }
            }
            dp = dp2;
        }
        return dp[m][n];
    }
}