int g[1005][1005];
class Solution {
public:
    vector< pair< int , int > > BackEdge;
    int color[1005];
    int sz = 0;
    int deg[1005];

    void dfs(int u, int p){
        color[ u ] = 1;
        for(int i = 1; i <= sz; i++){
            if(i == u){ continue; }
            if(!g[u][i]){ continue; }
            if(color[ i ] == 0){
                dfs(i, u);
            }
            else{
                if(color[ i ]==1){
                    BackEdge.push_back({u, i});
                }
            }
        }
        color[ u ]  = 2;
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> edges) {
        memset(color,0,sizeof(color));
        memset(deg,0,sizeof(deg));
        memset(g,0,sizeof(g));
        BackEdge.clear();
        int res = edges.size();
        sz = res;
        for(int i = 0; i < res; i++){
            g[ edges[i][0] ][ edges[i][1] ] = 1;
            deg[ edges[i][1] ]++;
        }
        int root = 1;
        for(int i = 1; i <= res; i++){
            if(!deg[i]){ root = i ; break; }
        }
        dfs(root,-1);
        vector< int > ans;
        if(BackEdge.size()){
            ans.push_back(BackEdge[0].first);
            ans.push_back(BackEdge[0].second);
        }
        else{
            int res = edges.size();
            for(int i = res-1; i >= 0; i--){
                int u = edges[i][0];
                int v = edges[i][1];
                if(deg[v] >= 2){
                    ans.push_back(u);
                    ans.push_back(v);
                    break;
                }
            }
        }
        edges.clear();
        return ans;
    }
};
