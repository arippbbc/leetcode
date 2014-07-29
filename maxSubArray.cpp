class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        int i=0, j=n-1, front=0, back=0;
        while(i<j){
            front+=A[i++];
            back+=A[j--];
            if(front<0) front=0;
            if(back<0) back=0;
        }
        return front+back;
    }
};
