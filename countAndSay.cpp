class Solution {
public:
    string int2str(int a){
        stringstream ss;
        ss << a;
        return ss.str();
    }
    
	string say(const string &s){
		int cnt = 1;
		char x = s[0];
		string res = "";

		for(size_t i=1; i<s.size(); ++i){
			if(s[i]==x){
				++cnt;
			}
			else{
				res += int2str(cnt) + x;
				x = s[i];
				cnt = 1;
			}
		}

		res += int2str(cnt) + x;
		return res;
	}

    string countAndSay(int n) {
        if(n==1) return "1";
        else return say(countAndSay(n-1));
    }
};
