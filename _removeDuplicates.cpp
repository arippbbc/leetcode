#include <iostream>
using namespace std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        int cur = A[0];
        for(int i=1; i<n; ++i){
            int x=0, j=i;
            while(j<n && A[j]==cur){
                ++x; ++j;
            }
            cout << x << endl;
            
            if(x>0){
                for(int j=i; j<n-x; ++j){
                    A[j] = A[j+x];
                }
                n = n-x;
            }
            cur = A[i];
        }
        return n;
    }
};

int main(){
    Solution s;
    int a[3] = {1,1,2};
    cout << s.removeDuplicates(a, 3) << endl;
}
