class Solution {
public:
    int majorityElement(vector<int> &num) {
        int sz = num.size();
        
        if(sz<3) return num[0];
        
        unordered_map<int, int> s;
        for(auto x: num){
            ++s[x];
        }
        
        for(auto x: s){
            if(x.second>sz/2) return x.first;
        }
    }
};
