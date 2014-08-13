class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;
         
        if(matrix[0][0]>target) return false;
        if(matrix[0][0]==target) return true;
        int i=0, j=m-1, t=0;
        if(matrix[i][0]==target || matrix[j][0]==target) return true;
        while(i<j-1){
            t = (i+j)/2;
            if(matrix[t][0]<target) i = t;
            else if(matrix[t][0]>target) j = t;
            else return true;
        }
        //cout << i << endl;

        i = matrix[j][0]<target?j:i;

        int x = 0, y = n-1;
        if(matrix[i][x]==target || matrix[i][y]==target) return true;
        while(x<y-1){
            t = (x+y)/2;
            if(matrix[i][t]<target) x = t;
            else if(matrix[i][t]>target) y = t;
            else return true;
        }
        return false;
    }
};
