class Solution {
public:

    int div(int &x, int y){
        if(x < y) return 0;
        int res = 1, d = y;
        while(x > d+d){
            if(d+d<=0) break;
            
            d += d;
            res <<= 1;
        }
        x -= d;
        return res;
    }
    
    int divide(int dividend, int divisor) {
        if(dividend==0 || divisor==0) return 0;
        if(divisor==1) return dividend;
        if(divisor==2) return dividend>>1;
        
        if(divisor==INT_MIN) {
            return dividend==INT_MIN?1:0;
        }

        bool sig=(dividend>0 && divisor>0) || (dividend<0 && divisor<0);

        if(dividend==INT_MIN){
            if(divisor>0){
                return divide(dividend+divisor, divisor)-1;
            }
            else {
                return divide(dividend-divisor, divisor)+1;
            }
        }

        dividend = abs(dividend);
        divisor = abs(divisor);
        
        int res = 0;
        while(dividend>=divisor){
            res += div(dividend, divisor);
        }
        
        return sig?res:(-res);
    }
};
