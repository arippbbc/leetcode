class Solution {
public:
    int sqrt(int x) {
        if(x<1) return 0;
        if(x<4) return 1;
        double a=x, b=x/2;
        while(a-b>0.1){
            a = b;
            b = b/2 + x/(b*2);  
        }
        return int(b);
    }
};
