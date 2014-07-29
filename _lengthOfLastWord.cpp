int lengthOfLastWord(const char *s) {
    const char *a = 0;
    while(*s){
        if(*s==' '){ 
            a = const_cast<char *>(s);
        }
        ++s;
    }
    int res = 0;
    while(*a){
        ++res;
        ++a;
    }
    return res-1;
}

#include <iostream>
using namespace std;
int main(){
    const char *s = "";
    cout << lengthOfLastWord(s) << endl;
}
