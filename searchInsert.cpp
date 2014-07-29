class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        if(n<1) return 1;
        int i = 0;
        while(i<n && A[i]<target){
            ++i;   
        }
        return i;
    }
};
