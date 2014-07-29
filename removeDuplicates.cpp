class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        int cur = A[0];
        for(int i=1; i<n; ++i){
            int x=0;
            while(i<n && A[i]==cur){
                ++x;
            }
            
            /*  /
            if(x>0){
                for(int j=i; j<n-x; ++j){
                    A[j] = A[j+x];
                }
                n = n-x;
            }
            cur = A[i];
            */
        }
        return n;
    }
};

#include <iostream>
using namespace std;

int main(){
    Solution s;
    int a[2] = {1,1};
    cout << s.removeDuplicates(a, 2) << endl;
}
