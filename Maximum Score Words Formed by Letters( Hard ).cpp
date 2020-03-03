//https://leetcode.com/problems/maximum-score-words-formed-by-letters/
class Solution {
public:
    int freq[30];
    bool check(vector< int >&V , string s){
        vector< int > t(27,0);
        for(int i = 0; i < s.size(); i++){
            int x = s[i]-'a';
            t[ x ]++;
            if( t[x] > V[x]){ return 0 ; }
        }
        for(int i = 0; i < 27; i++){
            V[i]-=t[i];
        }
        return 1;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        memset(freq,0,sizeof(freq));
        int k = words.size();
        int ans = 0;
        for(int i = 0; i < letters.size(); i++){
            int lol = letters[i]-'a';
            freq[ lol ]++;
        }
        for(int i = 0; i < (1<<k); i++){
            int cur = 0;
            vector< int > f(30,0);
            for(int ii = 0; ii < 26; ii++){ f[ii] = freq[ii] ; }
            for(int j = k-1 ; j >= 0; j--){

                if( (i & (1<<j) ) && j < words.size() && check(f,words[j]) ){

                    for(int ii = 0; ii < words[j].size(); ii++){
                        cur+=score[ words[j][ii]-'a' ];
                    }
                }

            }
            ans = max(ans,cur);
        }
        return ans;
    }
};
