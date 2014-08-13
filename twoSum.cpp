class Solution {
public:

    vector<int> twoSum(vector<int> &numbers, int target) {
        //std::unordered_multimap<int, int> x;
        std::unordered_multimap<int, int> x;
        for(size_t i=0; i!=numbers.size(); ++i){
            x.insert({numbers[i], i}); 
        }
        
        int a = 0, b = 0;
        for(size_t i=0; i!=numbers.size()-1; ++i){
            //auto r = x.equal_range(target-numbers[i]);
            size_t cnt = x.count(target-numbers[i]);
            if(cnt==1){
                a = i+1;
                b = x.find(target-numbers[i])->second+1;
            }
            
            if(cnt==2){
                auto range = x.equal_range(target-numbers[i]);
                for (auto it = range.first; it != range.second; ++it) {
                    if(it->second+1 > b) b = it->second+1;
                }
                a = i+1;
                break;
            }
            if(a < b) break;
        }
        
        vector<int> res = {a, b};
        return res;
    }
};

