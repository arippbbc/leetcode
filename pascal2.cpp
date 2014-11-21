class Solution {
public:
	vector<int> getRow(int rowIndex){
		vector<int> res;
		if(rowIndex<=1) return vector<int>(rowIndex+1,1);
		res.push_back(1);
		res.push_back(rowIndex);

		int n = rowIndex, m = 1;
		for(int i=2; i!=(rowIndex%2?rowIndex:rowIndex+1)/2 + 1; ++i){
			--n;
			++m;
			res.push_back(res[i-1]/m*n+res[i-1]%m*n/m);
		}

		for(int i=(rowIndex%2?rowIndex:rowIndex-1)/2; i!=-1; --i){
			res.push_back(res[i]);
		}
		return res;
	}
};
