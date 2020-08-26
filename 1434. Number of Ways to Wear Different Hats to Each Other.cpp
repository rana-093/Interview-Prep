class Solution {
public:
    using ll = long long int;
    ll dp[45][1<<11];

    const int mod =  (int)1e9+7;
    int len = 41;
    vector< int > h[55];
    int n = 0;

    ll solve(int cur, int mask){
        if(cur >= len){
            return  __builtin_popcount(mask) == n  ;
        }
        if(dp[cur][mask]!=-1){ return dp[cur][mask] ; }
        ll ans = 0LL;
        for(int i = 0; i < h[cur].size(); i++){
            int p = h[cur][i];
            if(mask&(1<<p)){ continue ;}
            ans+=solve(cur+1,mask|(1<<p)) % mod;
            ans%=mod;
        }
        ans+=solve(cur+1,mask) % mod;
        ans%=mod;
        ans+=mod;
        ans%=mod;
        return dp[cur][mask] = ans;
    }

    int numberWays(vector<vector<int>> hats) {
        n = hats.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < hats[i].size(); j++){
                h[ hats[i][j] ].push_back(i);
            }
        }
        memset(dp,-1,sizeof(dp));
        ll ans =  solve(1,0);
        cout << ans << endl;
        return ans;
    }
};
