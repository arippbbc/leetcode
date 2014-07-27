class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        vector<int>::reverse_iterator it=digits.rbegin();
        while(it != digits.rend() && *it == 9){
            res.insert(res.begin(), 0);
            ++it;
        }
        
        if(it != digits.rend()){
            res.insert(res.begin(), *it+1);
            ++it;
        }
        
        else{
            res.insert(res.begin(), 1);
        }
        
        while(it != digits.rend()){
            res.insert(res.begin(), *it);
            ++it;
        }
        
        return res;
    }
};
