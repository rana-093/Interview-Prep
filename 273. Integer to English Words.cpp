//RANA
class Solution {
public:
    vector< int > units = {1000000000, 1000000 , 1000, 100};
    vector< string > Sunits = { "Billion", "Million", "Thousand", "Hundred"};
    vector< string > num = { "Zero" , "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten"};
    vector< string > twodigits = { "Zero" , "One", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector< string > ones = {"Ten","Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    string parse(int x){
        string bal = "";
        int z = x / 100;
        if(z){ bal = bal + num[ z ] + " "+ "Hundred"; if(!(x % 100)){ return bal; } }
        x-=(z * 100);
        z = x / 10;
        if(z == 1){
            z = x % 10;
            bal = (bal.size()) ? ( bal + " "+ ones[z] ) : bal + ones[z];
            return bal;
        }
        else if(z>=2){
            bal = (bal.size()) ? ( bal + " "+ twodigits[z] ) : bal + twodigits[z];
            if(!(x%10)){ return bal; }
        }
        x-=(z * 10);
        if( x > 0){ bal = (bal.size()) ?  (bal + " " + num[x] ) : bal + num[x]; }
        return bal;
    }

    string numberToWords(int num) {
        string ans = "";
        if(num == 0){ return "Zero"; }
        for(int i = 0; i < units.size(); i++){
            int res = num / units[ i ];
            if(res == 0){ continue; }
            string x = parse(res);
            string temp = x + " " + Sunits[ i ];
            if(ans.size()){ ans+=" " + temp; }
            else{ ans+=temp; }
            num = num % units[ i ];
        }
        if(num) {ans = (ans.size()) ? (ans + " "+parse(num) ) : ans + parse(num); }
        return ans;
    }
};
