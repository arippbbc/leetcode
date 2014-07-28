class Solution {
public:
    int sqrt(int x) {
        int a=1, b=x/2;
        while(a<b){
            if(a*a<x){
                if(b-a>1){
                    a=(a+b)/2;
                }
                else{
                    a=a+1;
                }
            } 
            else if(b*b>x){
                if(b-a>1){
                    b=(a+b)/2;
                }
                else{
                    b=b-1;
                }
            } 
        }
        return a;
    }
};
