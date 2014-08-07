#include <iostream>
using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        int max = A[0], min=A[0], sum=A[0], res=A[0];
        for(int i=1;i<n;++i){
            sum+=A[i];
            if(sum>max){
                max = sum;
                if(max>res) res = max;
                if(min<0) res = max-min;
            }

            if(sum<min){
                min = sum;
            }

            if(res < A[i]){
                res = A[i];
            }
        }
        return res;
    }
};

int main(){
	int A[4] = {0, -3, 1, 1};
	Solution s;
	cout << s.maxSubArray(A, 4) << endl;
}
