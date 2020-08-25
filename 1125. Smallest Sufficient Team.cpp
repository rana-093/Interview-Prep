
int dp[61][(1<<16)+10];

class Solution {
public:
    map< string , int > mp;
    int msk[75];
    int k;
    int l;
    vector< int > ans;
    int solve(int cur, int mask){
        if(mask==((1<<k)-1)){ return  0; }
        if(cur >= l){ return 1<<29; }
        if(dp[cur][mask]!=-1){ return  dp[cur][mask] ; }
        int ans = 1<<29;
        ans = min(ans,1+solve(cur+1,mask|msk[cur]));
        ans = min(ans,solve(cur+1,mask));
        return dp[cur][mask] = ans;
    }

    void fun(int cur, int mask){
        if(mask==((1<<k)-1)){ return ;}
        if(cur >= l){ return; }
        int x = 1 + solve(cur+1,mask|msk[cur]);
        int y = solve(cur+1,mask);
        if(dp[cur][mask]==x){
            ans.push_back(cur);
            return fun(cur+1,mask|msk[cur]);
        }
        else{
            return fun(cur+1,mask);
        }
    }

    vector< int > smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        k = req_skills.size();
        for(int i = 0; i < req_skills.size(); i++){
            string s = req_skills[i];
            mp[ s ] = i;
        }
        l = people.size();
        memset(msk,0,sizeof(msk));
        for(int i = 0; i < people.size(); i++){
            for(int j = 0; j < people[i].size(); j++){
                int position = mp[ people[i][j] ];
                msk[i]|=(1<<position);
            }
        }

        memset(dp,-1,sizeof(dp));
        solve(0,0);
        fun(0,0);
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i] ;
            if(i!=ans.size()-1){ cout <<", "; }
            else{ cout << endl; }
        }
        return ans;
    }
};
