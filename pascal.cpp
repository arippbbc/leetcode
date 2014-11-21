class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > res;
        vector<int> tmp;
        if(numRows <= 0) return res;
        if(numRows == 1){
            tmp.push_back(1);
            res.push_back(tmp);
            return res;
        }
        
        if(numRows == 2){
            tmp.push_back(1);
            res.push_back(tmp);
            tmp.push_back(1);
            res.push_back(tmp);
            return res;
        }
        
        res.push_back(vector<int>(1,1));
        res.push_back(vector<int>(2,1));
        for(int i=2;i!=numRows;++i){
            res.push_back(vector<int>(1,1));
            for(int j=0; j!=i-1; ++j){
                res[i].push_back(res[i-1][j]+res[i-1][j+1]);
            }
            res[i].push_back(1);
        }
        
        return res; 
    }
};
