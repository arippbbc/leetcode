class Solution {
public:
    string int2str(int n){
        stringstream ss;
        ss << n;
        return ss.str();
    }

    string countAndSay(int n) {
        bool neg = n<0?true:false;
        n = n<0?-n:n;
        int r, cnt = 0;
        string 
        do {
            n = n/10;
            r = n%10;
            ++cnt;
            res 
        } while(n);
        
        
    }
};
