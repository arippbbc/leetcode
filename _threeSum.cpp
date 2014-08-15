class Solution {
public:
    void threeOrder(int &a, int &b, int &c){
        int x, y, z = a+b+c;
        x = min(min(a,b),c);
        z = max(max(a,b),c);
        y = z-x-y;
        a = x;
        b = y;
        c = z;
    }
    
    vector<vector<int> > threeSum(vector<int> &num) {
        std::sort(num.begin(), num.end());
        unordered_multimap<int, int> x;
        for(size_t i=0; i!=num.size(); ++i){
            x.insert({num[i], i});
        }
        
        vector<vector<int> > res;
        vector<int> tmp;
        for(size_t i=0; i!=num.size()-1; ++i){
            for(size_t j=0; j!=num.size(); ++j){
                if(num[i]-num[j]<=0){
                    auto range = x.equal_range(-num[i]-num[j]);
                    for (auto it = range.first; it != range.second; ++it) {
                        if(it->second!=i && it->second!=i+1){
                            tmp = {num[i], num[j], -num[i]-num[j]};
                            res.push_back(tmp);
                        }
                    }
                }
            }
        }
        return res;
    }
};
