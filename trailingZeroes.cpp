class Solution {
public:
    int trailingZeroes(int n) {
        int res = n/5, x = res/5;
        while(x>0){
            res += x;
            x /= 5;
        }
        return res;
    }
};
