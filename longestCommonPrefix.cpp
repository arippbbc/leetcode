class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
     
        string res = "";
        
        if(strs.size()<=0) return res;   
        
        int min_len = LONG_MAX;
        for(auto &s: strs){
            min_len = min_len>s.size()?s.size():min_len;
        }
        
        for(int i=0; i!=min_len; ++i){
            char c = '\0';
            for(auto &s: strs){
                if(c=='\0'){
                    c = s[i]; 
                    continue;
                }
                if(c!=s[i]) return res;
            }
            res += c;
        }
        return res;
    }
};
