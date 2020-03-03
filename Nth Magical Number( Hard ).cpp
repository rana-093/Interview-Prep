class Solution {
public:
    using ll = long long int ;
    ll mod = (ll)1e9+7;
    bool check(ll val,ll fl, ll A , ll B){
        ll g = __gcd(A,B);
        ll lcm = (1LL * A * B) / g ;
        ll lol = (val / A)  + (val / B) - (val / lcm);
        return lol >= fl;
    }
    ll nthMagicalNumber(ll N, ll A, ll B) {
        ll n = (ll) N;
        ll a = (ll) A;
        ll b = (ll) B;
        ll lo = 1LL;
        ll hi = (ll)1e18;
        ll ans = -1;
        while(lo <= hi){
            ll mid = (lo + hi) >> 1;
            if(check(mid,n,a,b)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        return ans % mod;
    }
};
