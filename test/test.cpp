#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:

    int div(int &x, int y){
        if(x < y) return 0;
        int res = 1, d = y;
        //cout << d << endl;
        while(x > d+d){
            //cout << x << "|" << d << endl;
            // won't work, it's write if not overflow
            //d += d;
            //if(d <= 0) break;
            //
            if(d+d<=0) break;
            
            d += d;
            res <<= 1;
        }
        //if(d>0) x -= d;
        x -= d;
        //cout << x << endl;
        return res;
    }
    
    int divide(int dividend, int divisor) {
        if(dividend==0 || divisor==0) return 0;

        // fuck this, abs(min_int) overflow because abs(min_int) > abs(max_int)

        if(divisor==std::INT_MIN) {
            return dividend == INT_MIN?1:0;
        }

        bool sig=(dividend>0 && divisor>0) || (dividend<0 && divisor<0);

        if(dividend==std::INT_MIN){
            if(divisor>0){
                return divide(divisor+divisor, divisor)-1;
            }
            else if(divisor<0){
                return divide(divisor-divisor, divisor)-1;
            }
        }

        dividend = abs(dividend);
        divisor = abs(divisor);
        
        int res = 0;
        if(divisor==1) res = dividend;
        else if(divisor==2) res = dividend>>1;
        
        else{
            while(dividend>divisor){
                res += div(dividend, divisor);
            }
        }
        return sig?res:(-res);
    }
};

int main(){
    Solution s;
    int x = -1010369383, y = -2147483648;
    cout << s.divide(x, y) << endl;
    cout << x/y << endl;;
}
