#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>
#include <set>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

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
        /* should not go here */
        else {inc = 0; return '0';}
    }

    string addBinary(string a, string b) {
        if(a=="0" && b=="0") return "0";
        int x = a.size(), y = b.size();
        if(x<=y){
            if(x==0) return b;
            string s = ""; 
            cout << s << endl;
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
            return s;
        }
        return addBinary(b, a);
    }

	vector<int> getRow(int rowIndex){
		vector<int> res;
		if(rowIndex<=1) return vector<int>(rowIndex+1,1);
		res.push_back(1);
		res.push_back(rowIndex);

		int n = rowIndex, m = 1;
		for(int i=2; i!=(rowIndex%2?rowIndex:rowIndex+1)/2 + 1; ++i){
			--n;
			++m;
			res.push_back(res[i-1]/m*n+res[i-1]%m*n/m);
		}

		for(int i=(rowIndex%2?rowIndex:rowIndex-1)/2; i!=-1; --i){
			res.push_back(res[i]);
		}
		return res;
	}

	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(n<=0 || !head) return head;
		/* special case */
		if(n==1 || !head->next) return NULL;
		ListNode *t1 = head, *t2 = head;

		int i=1;
		for(;i<=n && t2->next; ++i){
			t2 = t2->next;
		}

		if(i==n-1) return head->next;

		while(t2){
			t1=t1->next;
			t2=t2->next;
		}

		t1->next = t1->next->next;
		return head;
	}

	int strStr(char *haystack, char *needle) {
        if(!haystack || haystack=='\0') return -1;
		int res;
		char *p;
		for(p=needle, res=0; p!='\0' && haystack!='\0'; ++haystack){
			while(p!='\0' && haystack!='\0' && *p==*haystack){
				++p; ++haystack; ++ res;
			}

			if(!p) return res;
			if(!haystack) return -1;
		}
		return -1;
	}

	bool sameLine(Point &p1, Point &p2, Point &p3){
		return (p3.y-p2.y)*(p2.x-p1.x) == (p2.y-p1.y)*(p3.x-p2.x);
	}

	bool samePoint(Point &p1, Point &p2){
		return p1.x==p2.x && p1.y==p2.y;
	}

	/*
	int maxPoints(vector<Point> &points) {
		set<Point> s(points.begin(), points.end());
		if(s.size()<=2) return s.size();

		int res = 2, cur = 2;
		for(auto p1 = points.begin(); p1!=--(--points.begin()); ++p1){
			for(auto p2 = ++p1; p2!=--points.begin(); ++p2){
				cur = 2;
				for(auto p3 = ++p2; p3!=points.begin(); ++p3){
					if(sameLine(*p1, *p2, *p3)){
						++cur;
					}
				}
				if(cur>res) res = cur;
			}
		}
		return res;
	}
	*/

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int a=0, b=0;
		ListNode *tmpA = headA, *tmpB = headB;
		while(tmpA) { ++a; tmpA = tmpA->next; }
		while(tmpB) { ++b; tmpA = tmpB->next; }

		tmpA = headA;
		tmpB = headB;
		if(a>b){
			for(int i=0; i!=a-b; ++i) tmpA = tmpA->next;
		}
		else {
			for(int i=0; i!=b-a; ++i) tmpB = tmpB->next;
		}

		for(int i=0; i!=min(a,b); ++i) {
			if(tmpA == tmpB) return tmpA;
			tmpA = tmpA->next;
			tmpB = tmpB->next;
		}
		return NULL;
	}

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

	/*
    int atoi(const char *str) {
        if(*str=='\0') return 0;
        bool neg = false;
        if(*str=='-'){
        	neg = true;
        	++str;
        }

        int res = 0;
        while(*str!='\0'){
            if(*str>='0' && *str <='9') {
                res = 10*res + int(*str-'0');
                cout << res << endl;
                if(res<0) return 0; //overflow;
            }
            ++str;
        }
        return neg?-res:res;
    }
    */

	int findMin(vector<int> &num) {
		int sz = num.size();

		if(sz == 1) return num[0];
		if(sz == 2) return min(num[0], num[1]);

		int i = 0, j = sz-1, k = j/2;
		while(i<j){
			if(num[i]>num[k]){
				j = k;
			}

			if(num[i]<num[k]){
				i = k;
			}

			k = (i+j)/2;
		}
		return num[i];
	}
#include <cstdlib>
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
        int d1 = numDigits(v1), d2 = numDigits(v2);
        if(d1<=d2){
            for(auto i=0; i<d2-d1; ++i){
                v1 *=10;
            }

            if(v1>v2) return 1;
            if(v1<v2) return -1;
            if(v1==v2) return 0;
        }

        else return compare(v2, v1);
    }

    int compareVersion(string version1, string version2) {
        int x1, x2, y1, y2;
        parseVersion(version1, x1, y1);
        parseVersion(version2, x2, y2);
        if(x1<x2) return -1;
        if(x1>x2) return 1;
        if(x1==x2){
            if(y1<y2) return -1;
            if(y1>y2) return 1;
            return 0;
        }
    }
};

template<class T>
void print(const T& t){
	for(auto &x: t){
		cout << x << "|";
	}
	cout << endl;
}

int main(){
    Solution s;
    /*
    vector<int> x{1,2,3};
    cout << s.findMin(x) << endl;
    */

    string v = "01.1";
    int x, y;

    s.parseVersion(v, x, y);
    cout << s.numDigits(y) << endl;

    cout << x << "|" << y << endl;
    //int x = s.atoi("-1");
    //cout << x << endl;

    /*
    vector<int> x{1,2,3,4,5,6,7,8,9,0};
    for_each(x.begin(), x.end(), [](int x){cout << x << "|";});
    */

    /* count and say
    cout << s.countAndSay(4) << endl;
    */

    /*
    ListNode *headA = NULL;
    ListNode *headB = new ListNode(2);

    s.getIntersectionNode(headA, headB);
    */

    /*
    vector<Point> points;
    s.maxPoints(points);
    */

    /*
    string a = "1";
    string b = "1";
    //cout << s.addBinary(a, b).size() << endl;
    //cout << s.addBinary(a, b) << endl;
	*/

    /* strStr
    char *haystack = "";
    char *needle = "";
    cout << s.strStr(haystack, needle) << endl;
    */
}
