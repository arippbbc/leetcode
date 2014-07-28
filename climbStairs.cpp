class Solution {
public:
    int climbStairs(int n) {
        if(n<=2) return n;
        int a=1, b=2, c;
        for(int i=2; i!=n; ++i){
            c = b;
            b = a+b;
            a = c;
        }
        return b;
    }
};
