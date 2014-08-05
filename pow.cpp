#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double pow(double x, int n) {
        if(n==0) return 1.;
        if(n==1) return x;
        //if(n==-1) return 1/x;
        int m = abs(n), z = 1;
        double res = x;
        while(m>1){
            res *= res;
            m /= 2;
            z *= 2;
        }
        
        res *= pow(x, abs(n)-z);
        if(n<0) res = 1/res;
        return res;
    }
};


int main(){
    double x = 8.88023;
    int n = 3;
    Solution s;
    cout << s.pow(x, n) << endl;
}
