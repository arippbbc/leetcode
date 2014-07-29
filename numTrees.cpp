class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        if(n<3) return n;
        int res=0;
        for(int i=0; i!=n; ++i){
            res += numTrees(i)*numTrees(n-1-i);
        }
        return res;
    }
};
