class Solution {
public:
    char intToAscii(unsigned int n){
        if(n==0) return 'Z';
        else return static_cast<char>(n+64);
    }
    
    string convertToTitle(int n) {
        int r = 0;
        string res;
        while(n>0){
            res = intToAscii(n%26) + res;
            if(n%26 == 0) n = n/26 - 1;
            else n /= 26;
        }
        return res;   
    }
};
