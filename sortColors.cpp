class Solution {
public:
    void sortColors(int A[], int n) {
        int r=0, w=0, b=0;
        for(int i=0;i!=n;++i){
            if(A[i]==0) ++r;
            if(A[i]==1) ++w;
            if(A[i]==2) ++b;
        }
        
        for(int i=0;i!=r;++i){
            A[i]=0;
        }
        for(int i=r;i!=r+w;++i){
            A[i]=1;
        }
        for(int i=r+w;i!=n;++i){
            A[i]=2;
        }
    }
};
