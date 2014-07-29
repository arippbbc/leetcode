class Solution {
public:
    unsigned int getDigits(unsigned int x){
        int res=0;
        while(x){
            ++res;
            x/=10;
        }
        return res;
    }
    
    int powofTen(unsigned int n){
        int res=1;
        for(int i=0; i!=n; ++i){
            res*=10;
        }
        return res;
    }
    
    bool isPalindrome(int x) {
        if(x==0) return true;
        
        if(x<0){
            //if(-x<0) 
            return false;
            //x = -x;
        }
        
        int digits = getDigits(x);
        while(digits>1){
            if(x/powofTen(digits-1) != x%10) return false;
            x = x%powofTen(digits-1)/10;
            digits-=2;
        }
        return true;
    }
};
