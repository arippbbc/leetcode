class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        set<int> row, column;
        for(int i=0; i!=matrix.size(); ++i){
            for(int j=0; j!=matrix[i].size(); ++j){
                if(matrix[i][j]==0){
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        
        for(int i=0; i!=matrix.size(); ++i){
            if(row.find(i)!=row.end()){
                for(auto &y: matrix[i]){
                    y = 0;
                }
            }
            else{
                for(auto &y: column){
                    matrix[i][y] = 0;
                }
            }
        }
    }
};
