
class Solution {
public:
    deque< pair< int, int > > dq;
    set< int > vis;

    void print(deque< pair< int, int > > &dq){
        for(int i = 0; i < dq.size(); i++){
            cout << dq[i].first << " , ";
        }
        cout << endl;
    }

    int totalFruit(vector<int> tree) {
        int ans = 0;
        for(int i = 0; i < tree.size(); i++){
            vis.insert(tree[i]);
            if(vis.size() <= 2){
                dq.push_back({tree[i], i});
            }
            else{
                int sz = dq.size();
                ans = max(ans,sz);
                int lol = dq.back().first;
                int pivot = -1;
                int type = 0;
                for(int i = dq.size()-1; i >= 0; i--){
                    if(dq[i].first!=lol){
                        type = dq[i].first;
                        pivot = dq[i].second ;
                        break;
                    }
                }
                vis.erase(type);
                while(dq.front().second <= pivot && dq.size()){
                    dq.pop_front();
                }
                vis.insert(tree[i]);
                dq.push_back({tree[i],i});
            }
        }
        ans = max(ans,(int)dq.size());
        return ans;
    }

};
