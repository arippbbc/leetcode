class Solution {
public:
    char bitAdd(const char a, const char b, int &inc){
        if(a=='0' && b=='0' && inc==0){inc = 0; return '0';}
        if(a=='0' && b=='0' && inc==1){inc = 0; return '1';}
        if(a=='0' && b=='1' && inc==0){inc = 0; return '1';}
        if(a=='0' && b=='1' && inc==1){inc = 1; return '0';}
        if(a=='1' && b=='0' && inc==0){inc = 0; return '1';}
        if(a=='1' && b=='0' && inc==1){inc = 1; return '0';}
        if(a=='1' && b=='1' && inc==0){inc = 1; return '0';}
        if(a=='1' && b=='1' && inc==1){inc = 1; return '1';}
    }

    string addBinary(string a, string b) {
        if(a=="0" && b=="0") return "0";
        int x = a.size(), y = b.size();
        if(x<=y){
            if(x==0) return b;
            string s = ""; 
            int inc = 0;
            /*
            for(int i=y-1; i>=0; --i){
                if(i-y+x>=0) s = bitAdd(a[i-y+x], b[i], inc) + s;
                else s = bitAdd('0', b[i], inc) + s; 
            }
            if(inc) s = "1" + s;
            return s;
            */
            
            int i = x, j = y;
            while(i){
                s = bitAdd(a[i-1], b[j-1], inc) + s;
                --i; --j;
            }
            
            while(j){
                s = bitAdd('0', b[j-1], inc) + s;
                --j;
            }
            
            if(inc){
                s = "1" + s;
            }
            return s;
        }
        return addBinary(b, a);
    }
};
