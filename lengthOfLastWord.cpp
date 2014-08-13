class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int res=0, res2=0;
        
        while(*s){
            if(*s!=' ') ++res;
            else {
                res2=res>0?res:res2;
                res=0;
            }
            ++s;
        }
        
        if(res>0) return res;
        return res2;
    }
};
