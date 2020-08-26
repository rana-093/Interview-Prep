
class Solution {
public:
    const int offset = 1001;
    int dp[20][2005];
    vector< int > V;
    int k;

    int solve(int cur, int val){
        if(cur >= V.size()){ return val==k; }
        if(dp[cur][val+offset]!=-1){ return dp[cur][val+offset]; }
        int x = solve(cur+1,val-V[cur]) + solve(cur+1,val+V[cur]);
        return  dp[cur][val+offset] = x;
    }

    int findTargetSumWays(vector<int> nums, int S) {
        V = nums;
        k = S;
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,0);
        return ans;
    }
};
