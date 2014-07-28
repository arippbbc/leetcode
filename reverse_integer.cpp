class Solution {
public:
    int reverse(int x) {
        if(x<10 && x>-10) return x;
        int y = abs(x);
        int r = 0, res = 0;
        while(y){
            r = y%10;
            y = y/10;
            res = res*10 + r;
        }
        return x>0?res:(-res);
    }
};
