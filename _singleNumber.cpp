class Solution {
public:
    int singleNumber(int A[], int n) {
        std::unordered_map<int, int> a;
        for(int i=0; i!=n; ++i){
            ++a[A[i]];
        }
        
        for(auto it=a.begin();it!=a.end();++it){
            if(it->second==1) return it->first;   
        }
    }
};
