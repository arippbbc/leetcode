class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for(auto &c: s){
            if(c=='(' || c=='{' || c=='[') t.push(c);
            if(c==')'){
                if(t.empty()) return false;
                else {
                    if(t.top() != '(') return false;
                    else t.pop();
                }
            }
            
            if(c=='}'){
                if(t.empty()) return false;
                else {
                    if(t.top() != '{') return false;
                    else t.pop();
                }
            }
            
            if(c==']'){
                if(t.empty()) return false;
                else {
                    if(t.top() != '[') return false;
                    else t.pop();
                }
            }
        }
        
        return t.empty();
    }
};
