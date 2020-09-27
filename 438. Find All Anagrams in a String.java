import java.util.*;
import java.io.*;

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> L =  new ArrayList<Integer>();
        List<Integer> [] csum = new ArrayList[30];
        List< Integer >[] X = new ArrayList[30];
        for(int i = 0; i < 30; i++){
            csum[i] = new ArrayList<Integer>();
            X[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < p.length(); i++){
            int res = p.charAt(i) - 'a';
            for(int j = 0; j < 26; j++){
                if(res == j){ X[j].add(1) ; }
                else{ X[j].add(0) ; }
            }
        }

        for(int i = 0; i < s.length(); i++){
            int res = s.charAt(i) - 'a';
            for(int j = 0; j < 26; j++){
                if(res == j){ csum[j].add(1) ; }
                else{ csum[j].add(0) ; }
            }
        }
        for(int j = 0; j < 26; j++){
            for(int i = 1; i < s.length(); i++){
                int cur = csum[j].get(i) + csum[j].get(i-1);
                csum[j].set(i,cur);
            }
        }
        for(int j = 0; j < 26; j++){
            for(int i = 1; i < p.length(); i++){
                int cur = X[j].get(i) + X[j].get(i-1);
                X[j].set(i,cur);
            }
        }
        int ls = s.length() - 1;
        int lp = p.length() - 1;
        for(int i = 0; (i + lp) < s.length(); i++){
            boolean flag = true;
            for(int j = 0; j < 26; j++){
                int res = 0 , x = 0;
                if(i==0){
                    res  = X[j].get(lp);
                    x = csum[j].get(lp);
                    if( x >= res){ continue; }
                    flag = false;
                }
                else{
                    res = X[j].get(lp);
                    x = csum[j].get(i+lp) - csum[j].get(i-1);
                    if( x >= res){ continue; }
                    flag = false;
                }
            }
            if(flag){
                L.add(i);
            }
        }
        return  L;
    }
}
