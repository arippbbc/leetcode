class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size()==0) return 0;
        int pf = 0;
        for(vector<int>::const_iterator it=prices.begin(); it!=prices.end()-1; ++it){
            if(*(it+1) > *it){
                pf += *(it+1) - *it;
            }
        }
        return pf;
    }
};
