class Solution {
public:
    int N = (int)1e5+5;
    int par[100010];
    int sub[100010];
    vector< int > V[100015];
    int ans = -1;
    void factorize(int n){
        bool fl = 0 ;
        for(int i = 2; i*i <= n; i++){
            if(n%i==0){
                fl = 1;
                V[ i ].push_back(n);
                if(i*i!=n){
                    V[ n/i ].push_back(n);
                }
            }
        }
        if(fl==0){
            V[n].push_back(n);
        }
    }

    int find(int r){
        return (par[r]==r) ? r : find(par[r]);
    }

    bool merge(int u, int v){
        int x = find(u);
        int y = find(v);
        if(x==y){ return 0 ; }
        if(sub[x] < sub[y]){ swap(x,y) ; }
        par[y] = x;
        sub[x]+=sub[y];
        ans = max(ans,sub[x]);
        return 1;
    }

    int largestComponentSize(vector<int>& A) {
        for(int i = 1; i <= N; i++){
            par[ i ] =  i ;
            sub[ i ] = 1;
        }
        for(int i = 0; i < A.size(); i++){
            factorize(A[i]);
        }
        for(int i = 2; i <= N; i++){
            sort(V[i].begin(),V[i].end());
        }
        for(int i  = 2; i <= 100000; i++){
            if(V[i].size()==0){ continue ; }
            int x = V[i].front();
            for(int j = 1; j < V[i].size(); j++){
                merge(x,V[i][j]);
            }
        }
        return ans;
    }
};
