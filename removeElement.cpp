class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for(int i=0;i<n;++i){
            if(A[i] == elem){ 
                //can't use for(int j=i; j!=n-1-res; ++j){
                for(int j=i; j<n-1; ++j){
                    A[j] = A[j+1];
                }
                --n;
                // necessary
                if(i<n){ 
                    --i;
                }
            }
        }
        return n;
    }
};
