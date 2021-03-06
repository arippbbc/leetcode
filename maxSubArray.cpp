class Solution {
public:
    int maxSubArray(int A[], int n) {
        if(n==0) return 0;
        if(n==1) return A[0];
        int max = A[0], min=A[0], sum=A[0], res=A[0];
        for(int i=1;i<n;++i){
            sum+=A[i];

            if(sum-min>res){
            	res = sum-min;
            }

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
