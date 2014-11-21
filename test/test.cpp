#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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
    }

    string addBinary(string a, string b) {
        int x = a.size(), y = b.size();
        if(x<=y){
            if(x==0) return b;
            string s = ""; 
            cout << s << endl;
            int inc = 0;
            for(int i=y-1; i>=0; --i){
                if(i-y+x>=0) s = bitAdd(a[i-y+x], b[i], inc) + s;
                else s = bitAdd('0', b[i], inc) + s; 
            }
            if(inc) s = "1" + s;
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
    string a = "0";
    string b = "0";
    //cout << s.addBinary(a, b).size() << endl;
    //cout << s.addBinary(a, b) << endl;
    for(int i=5; i!=6; ++i){
    	print(s.getRow(i));
    }
}
