class Solution {
public:
    int dp[100][100];
    int numDecodings(string s) {
        
    int dp[200000 + 5];
    int N = 200000 + 5;
    for(int i = 0; i < N; i++){
        dp[i] = 0;
    }
    bool ok = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i]=='0' && s[i+1]=='0'){
            ok = true;
        }
        if(i-1 >= 0 && s[i]=='0' && s[i-1] >= '3'){ ok = 1; }
    }
    if(ok){
        return 0;
    }
    dp[0] = 1;
    for(int i = 0; i < s.size(); i++){
        int l = i+1;
        if(s[i]=='0'){
            if(l-2 >= 0 )dp[l]+=dp[l-2]; continue;
        }
        dp[l]+= dp[l-1];
        if(i-1 >=0){
            int bal = (s[i-1]-'0' ) * 10 + (s[i]-'0') ;
            if(bal <= 26 && bal!=0 && s[i-1]!='0'){
                dp[l]+=dp[l-2];
            }
        }
    }
        return  dp[s.size()] ;
    }
   
};
