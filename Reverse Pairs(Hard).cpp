class Solution {
public:
    using ll = long long int;
    unordered_map< int , int > mp;
    set< ll > S;
    int N = (int)1e5+5;
    ll BIT[100010];
    void update(int idx,int val){
        while( idx < N){
            BIT[ idx ]+=val;
            idx+=( idx & -idx);
        }
    }
    ll query(int idx){
        ll sum = 0LL;
        while( idx > 0){
            sum+=BIT[ idx ];
            idx-=( idx & -idx);
        }
        return sum;
    }
    ll reversePairs(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            S.insert(nums[i]);
        }
        vector< int > V = nums;
        sort(V.begin(),V.end());
        int cnt  = 0;
        for(int i = 0; i < V.size(); i++){
            mp[ V[i] ] = i+1;
        }
        int ans = 0;
        for(int i = nums.size()-1; i >= 0 ; i--){
            int el = lower_bound(V.begin(),V.end(),(double) nums[i] / (double) 2.0 ) - V.begin();
            ans+=query( el );
            update(mp[ nums[i] ],+1);
        }
        return ans;
    }
};
