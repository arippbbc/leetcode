class Solution {
public:
    int asciiToNumber(char c){
        if(c<='Z' && c>='A') return c-64;
    }
    
    int titleToNumber(string s) {
        int res = 0, sz = s.size();
        for(int i = 0; i < sz; ++i){
            res = res*26 + asciiToNumber(s[i]);
        }
        
        return res;
    }
};
