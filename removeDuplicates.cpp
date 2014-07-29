class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<2) return n;
        int cur = A[0], res = 1, j=1;
        for(int i=1; i<n; ++i){
            while(i<n && A[i]==cur){
                ++i;
            }
            if(i<n){
                ++res;
                A[j++] = A[i]; 
                cur = A[i];
            }
        }
        return res;
    }
};
