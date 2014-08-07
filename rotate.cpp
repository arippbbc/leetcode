class Solution {
public:
    void print(vector<vector<int> > &matrix){
        int sz = matrix.size();
        for(int i=0;i<sz;++i){
            for(int j=0;j<sz;++j){
                cout << matrix[i][j] << endl;
            }
        }
    }

    void rotate(vector<vector<int> > &matrix) {
        int sz = matrix.size();
        int lmt = sz&1?(sz/2+1):sz/2;
        int tmp;
        for(int i=0;i<lmt;++i){
            for(int j=i;j<sz-1-i;++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[sz-1-j][i];
                matrix[sz-1-j][i] = matrix[sz-1-i][sz-1-j];
                matrix[sz-1-i][sz-1-j] = matrix[j][sz-1-i];
                matrix[j][sz-1-i] = tmp;
            }
        }
    }
};
