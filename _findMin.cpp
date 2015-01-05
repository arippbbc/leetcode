class Solution {
public:
    int findMin(vector<int> &num) {
        int sz = num.size();
        
        if(sz == 1) return num[0];
        if(sz == 2) return min(num[0], num[1]);
        
        int i = 0, j = sz-1, k = j/2;
        while(i<j){
            if(num[i]>num[k]){
                j = k;
            }
            
            if(num[i]<num[k]){
                i = k;
            }
            
            k = (i+j)/2;
        }
        return num[i];
    }
};
