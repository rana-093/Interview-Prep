import java.util.*;

class Solution {
    int x , y , z;
    int n;

    long gcd(long a , long b){
        if(b==0){ return  a; }
        return gcd(b,a%b);
    }

    long lcm(long a, long b){
        return (a*b)/ gcd(a,b);
    }

    boolean isValid(long val){
        long add  = (val/x) + (val/y) + (val/z);
//        System.out.println(add);
        add-=(val/lcm(x,y));
        add-=(val/lcm(y,z));
        add-=(val/lcm(x,z));
        add+=(val/lcm(x,lcm(y,z)));
        return (add >= n) ? true : false;
    }

    public int nthUglyNumber(int n, int a, int b, int c) {
        long ans = 0;
        this.x = a;
        this.y = b;
        this.z = c;
        this.n = n;
        long lo = 0 , hi = (long)1e18;
        while(lo <= hi){
            long mid = (lo+hi) / 2;
            if(isValid(mid)){
                ans = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }
        }
        return (int)ans;
    }
}
