class Solution {
public:
    void parseVersion(string &v, int &x, int &y){
        size_t n = v.find('.');
        if (n == std::string::npos) {
            x = atoi(v.c_str());
            y = 0;
        }
        else{
            x = atoi(v.substr(0, n).c_str());
            y = atoi(v.substr(n+1, v.size()-n).c_str());
        }
    }
    
    int numDigits(int number){
        if(number==0) return 1;
        
        int digits = 0;
        while (number) {
            number /= 10;
            digits++;
        }
        return digits;
    }
    
    int compare(int v1, int v2){
        if(v1>v2) return 1;
        if(v1<v2) return -1;
        if(v1==v2) return 0;
    }
    
    int compareVersion(string version1, string version2) {
        size_t n1 = version1.find('.'), n2 = version2.find('.');
        
        int x1, x2;
        if (n1 == std::string::npos) {
            x1 = atoi(version1.c_str());
            if(n2 == std::string::npos){
                x2 = atoi(version2.c_str());
                return compare(x1, x2);
            }
            else { 
                x2 = atoi(version2.substr(0, n).c_str()); 
                if(x1 <= x2) return -1;
                if(x1 > x2) return 1;
            }
        }
    }
};
