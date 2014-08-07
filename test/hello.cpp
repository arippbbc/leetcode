#include <iostream>
#include <vector>
using namespace std;

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
        int tmp;
        for(int i=0;i<sz/2;++i){
            for(int j=i;j<sz/2-i;++j){
                tmp = matrix[i][j];
                matrix[i][j] = matrix[sz-1-j][i];
                matrix[sz-1-j][i] = matrix[sz-1-i][sz-1-j];
                matrix[sz-1-i][sz-1-j] = matrix[j][sz-1-i];
                matrix[j][sz-1-i] = tmp;
            }
        }
    }
};

int main(){
	vector<vector<int> > A = {{1,2}, {3,4}};
	Solution s;
    s.print(A);
	s.rotate(A);
    s.print(A);
}
