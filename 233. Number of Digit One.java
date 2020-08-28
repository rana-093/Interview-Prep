
class Solution {
    long[][][] dp = new long[20][3][20];
    ArrayList<Integer> digit = new ArrayList<>();

    long solve(int cur,int less, int val){
        if(cur >= digit.size()){
                return val;
        }
        if(dp[cur][less][val]!=-1){ return dp[cur][less][val]; }
        long ans = 0;
        if(less==0){
            for(int i = 0; i <= digit.get(cur); i++){
                int f = ( i < digit.get(cur)) ? 1 : 0;
                ans+= solve(cur+1, less|f, val+( (i==1) ? 1 : 0 ));
            }
        }
        else{
            for(int i = 0; i <= 9; i++){
                ans+=solve(cur+1, 1, val+( (i==1) ? 1 : 0 ));
            }
        }
        return dp[cur][less][val] = ans;
    }

    public int countDigitOne(int n) {
        int x = n;
        while(x > 0){
            digit.add(x%10);
            x/=10;
        }
        Collections.reverse(digit);
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 20; k++){
                    dp[i][j][k] = -1;
                }
            }
        }
//        for(int i = 0; i < digit.size(); i++){
//            System.out.print(digit.get(i)+" ");
//        }
//        System.out.println();
        int res = (int) solve(0,0, 0);
        System.out.println(res);
        return res;
    }
}
