class Solution {
public:
    int maxArea(vector<int> &height) {
        int size = height.size();
        if(size<2) return 0;
        
        int res=0, tmp;
        for(int i=0;i!=size-1;++i){
            for(int j=i+1;j!=size;++j){
                tmp = min(height[i],height[j])*(j-1);
                if(tmp>res) res=tmp;
            }
        }
        return res;
    }
};
