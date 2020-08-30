
class Solution {
    public int nthUglyNumber(int n) {

        Set< Long > S = new TreeSet<Long>();
        final long inf = Long.MAX_VALUE;
        for(double i = 0; i <= 20; i++){
            for(double j = 0; j <= 40; j++){
                for(double k = 0; k <= 60; k++){
                    double res = Math.pow((double)5 , i);
                    double a = Math.pow((double)3 , j);
                    if(res > (inf / a) ){ break; }
                    res*=a;
                    double b = Math.pow((double)2 , k);
                    if( res > (inf / b) ){ break; }
                    res*=b;
                    long cur = (long)res;
                    S.add(cur);
                }
            }
        }
        Iterator<Long> itr = S.iterator();
        long ans = 0 ,  res = 1;
        while(itr.hasNext() && res <= n){
            ans = itr.next();
            ++res;
        }
        return (int)ans;
    }
}
