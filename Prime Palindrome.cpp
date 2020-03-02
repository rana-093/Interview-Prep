class Solution {
public:
    int primePalindrome(int n) {
        const int N = (int)1e3+5e2;
        vector< int > V;
        vector< string > Vs;
        for(int i = 0; i < 10; i++){
            string s = to_string(i);
            Vs.push_back(s);
            if( i > 1 && isPrime(i) ) V.push_back(i);
        }
        int cnt = 0;
        for(int i = 1; i < N; i++){
            string s = to_string(i);
            string t = s;
            reverse(t.begin(),t.end());
            for(int ii = 0; ii < Vs.size(); ii++) {
                string ss = s + Vs[ii] + t;
                int b = atol( ss.c_str() );
                if(isPrime(b)) {  V.push_back(b) ; }
            }
            s = s + t;
            long long bal = std::atol(s.c_str());
            if(isPrime(bal)) V.push_back(bal);
        }
        sort(V.begin(),V.end());
        if(binary_search(V.begin(),V.end(),n)){
            return n;
        }
        int ans = *upper_bound(V.begin(),V.end(),n);
        return ans;

    }
    bool isPrime(int x){
        for(int i = 2; i * i <= x; i++){
            if(x%i==0){ return 0 ; }
        }
        return 1;
    }

};
