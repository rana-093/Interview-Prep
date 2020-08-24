
class Solution {
public:
    int dp[15][2];
    vector< int > digit;
    int k ;
    int n;
    vector< int > num;

    int solve(int taken, int val,bool flag){
        if(taken < 0){ return 0; }
        if(taken == 0){ return val <= n; }
        if(dp[taken][flag]!=-1){ return dp[taken][flag] ; }
        int ans = 0;
        int cur = k - taken ;
        for(int i = 0; i < digit.size(); i++){
            if((( val * 10 ) + digit[i]) <= n ){
                if(!flag && digit[i] > num[ cur ]){ break ; }
                ans+=solve(taken - 1 , ( val * 10 ) + digit[i], flag | (digit[i] < num[cur]));
            }
            else{ break ;}
        }
        return dp[taken][flag] = ans;
    }

    int MyPow(int a, int p){
        int ans = 1;
        for(int i = 1; i <= p; i++){ ans*=a ; }
        return ans;
    }

    int atMostNGivenDigitSet(vector<string> D, int N) {
        for(auto &x : D){
            int y = stoi(x);
            digit.push_back(y);
        }
        int res = 0;
        int x = N;
        n = N;
        while(x){
            ++res;
            num.push_back(x%10);
            x/=10;
        }
        reverse(num.begin(),num.end());
        int ans = 0;
        for(int i = 1; i < res; i++){
            ans+=MyPow(digit.size(),i);
        }
        k = res;
        memset(dp,-1,sizeof(dp));
        ans+=solve(res,0,false);
        cout << ans << endl;
        return ans;
    }
};
