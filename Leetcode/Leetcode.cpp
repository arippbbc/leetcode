#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <set>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <algorithm>
#include <utility>
#include <iterator>
#include <stack>

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
	/*************** NO. 1 Two Sum ***************/
    vector<int> twoSum(vector<int> &numbers, int target) {
        size_t sz = numbers.size();
        if(sz<1) return {};

        unordered_multimap<int, size_t> x;

        for(size_t i=0; i!=sz; ++i){
            x.insert({numbers[i], i+1});
        }

        int a = 0, b = 0;
        auto xend = x.end();
        for(size_t i=0; i!=sz-1; ++i){
            auto range = x.equal_range(target-numbers[i]);
            if(range.first!=xend){
                for(auto it=range.first; it!=range.second; ++it){
                    if(it->second!= i+1){
                        a = i+1;
                        b = it->second;
                        if(a>b) swap(a,b);
                        return {a, b};
                    }
                }
            }
        }
        return {};
    }

	/*************** NO. 1 Two Sum (does not work with duplicate elements ***************/
//    vector<int> twoSum(vector<int> &numbers, int target) {
//        size_t sz = numbers.size();
//        unordered_map<int, size_t> x;
//        for(size_t i=0; i!=sz; ++i){
//            x.insert({numbers[i], i+1});
//        }
//
//        int a = 0, b = 0;
//        auto xend = x.end();
//        for(size_t i=0; i!=sz-1; ++i){
//            auto r = x.find(target-numbers[i]);
//            if(r!=xend){
//					a = i+1;
//					b = r->second;
//					if(a==b) continue;
//					if(a>b) swap(a,b);
//					return {a, b};
//            }
//        }
//    	return {};
//    }

    /*************** NO. 2 Add Two Numbers ***************/
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;

        ListNode *res = new ListNode(0);
        ListNode *cur = res;
        int tmp = 0, one = 0;
        while(l1!=nullptr || l2!=nullptr){
        	tmp = one + (l1!=nullptr?l1->val:0) + (l2!=nullptr?l2->val:0);
        	cur->val = tmp<10?tmp:tmp-10;
        	one = tmp<10?0:1;
        	if(l1) l1 = l1->next;
        	if(l2) l2 = l2->next;
        	if((l1 or l2) or (one)){
        		cur->next = new ListNode(0);
        	}
        	cur = cur->next;
        }

        if(one){
        	cur->val = 1;
        }
        return res;
    }

    /*************** NO. 3 Longest Substring Without Repeating Characters ***************/
    int lengthOfLongestSubstring(string s) {
        auto sz = s.size();
        if(sz<=1) return 0;
    }

    /*************** NO. 4 Median of Two Sorted Arrays ***************/
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
    	if(m==0 && n==0) return 0.0;
        if(m==0) return B[n/2];
        if(n==0) return A[m/2];

        if(A[m/2] == B[n/2]) return A[m/2];


    }

    /*************** NO. 7 Reverse Integer ***************/
    int reverse(int x) {
    	if(x>-10 && x<10) return x;

    	if(x==numeric_limits<int>::min()) return 0;
        int y = abs(x);

        int res = 0;
        while(y){
        	if(res>numeric_limits<int>::max()/10) return 0;
        	res = res*10 + y%10;
        	y /= 10;
        }
        return x>0?res:-res;
    }

    /*************** NO. 9 Palindrome Number ***************/
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        int div = 1;
        while(div<=x/10)
            div *= 10;
        while(x>0)
        {
            if(x/div!=x%10)
                return false;
            x = (x%div)/10;
            div /= 100;
        }
        return true;
    }

    /*************** NO. 13 Roman to Integer ***************/
    inline int romanchar2int(char r){
    	switch(r){
    		case 'I': return 1;
    		case 'V': return 5;
    		case 'X': return 10;
    		case 'L': return 50;
    		case 'C': return 100;
    		case 'D': return 500;
    		case 'M': return 1000;
    		default: return 0;
    	}
    }

    int romanToInt(string s) {
    	auto sz = s.size();
    	if(sz==0) return 0;
    	if(sz==1) return romanchar2int(s[0]);

    	int i=0, res=0, a, b;
    	for(; i<sz-1; ++i){
    		a = romanchar2int(s[i]);
    		b = romanchar2int(s[i+1]);
    		if(a<b) { res += b-a; ++i; }
    		if(a==b) { res += a+b; ++i; }
    		if(a>b) { res += a;}
    	}

    	if(i==sz-1) res += romanchar2int(s[sz-1]);
    	return res;
    }

    /*************** NO. 15 Longest Common Prefix ***************/
    string longestCommonPrefix(vector<string> &strs) {
    	auto sz = strs.size();
    	if(sz==0) return string();
    	if(sz==1) return strs[0];

    	string res{""};
    	size_t mx = numeric_limits<size_t>::max();
    	for(auto &str: strs) mx = min(mx, str.size());

    	char c; size_t i=0;
    	for(; i<mx; ++i){
    		c = strs[0][i];
    		for(auto j=1; j<sz; ++j){
    			if(strs[j][i]!=c) return strs[0].substr(0, i);
    		}
    	}
    	return strs[0].substr(0, i);
    }

    /*************** NO. 15 3Sum ***************/
    vector<vector<int> > threeSum(vector<int> &num) {
    	auto sz = num.size();
    	vector<vector<int>> res;
    	if(sz<3) return res;

    	sort(num.begin(), num.end());

    	for(unsigned int i=0; i<sz-2; ++i){
    		if(i>0 && num[i]==num[i-1]) continue;
    		int j=i+1, k=sz-1;
    		while(j<k){
    			if(num[i]+num[j]+num[k]==0){
    				res.push_back({num[i], num[j], num[k]});
    				do {
    					++j;
    				} while(num[j]==num[j-1]);
    				do {
    					--k;
    				} while(num[k]==num[k+1]);
    			}

    			else if(num[i]+num[j]+num[k]<0){
    				do {
    					++j;
    				} while(num[j]==num[j-1]);
    			}

    			else {
    				do {
    					--k;
    				} while(num[k]==num[k+1]);
    			}
    		}
    	}

    	//sort(res.begin(), res.end());
    	//res.erase(unique(res.begin(), res.end()), res.end());
    	return res;
    }

    /*************** NO. 16 3Sum Closest ***************/
	int threeSumClosest(vector<int> &num, int target) {
		auto sz = num.size();
		vector<vector<int>> res;
		if(sz<3) return target;

		sort(num.begin(), num.end());

		if(num[0]+num[1]+num[2] >= target) return num[0]+num[1]+num[2];
		if(num[sz-3]+num[sz-2]+num[sz-1] <= target) return num[sz-3]+num[sz-2]+num[sz-1];

		int dis = numeric_limits<int>::max();
		for(unsigned int i=0; i<sz-2; ++i){
			if(i>0 && num[i]==num[i-1]) continue;
			int j=i+1, k=sz-1, cur;
			//bool cross = false;
			while(j<k){
				cur = num[i]+num[j]+num[k];
				if(cur==target){
					return target;
				}

				else if(cur<target){
					//if(dis!= numeric_limits<int>::max() && dis>0) cross = true;
					if(abs(dis) > abs(target-cur)) dis = cur-target;
					//if(cross) break;
					do {
						++j;
					} while(num[j]==num[j-1]);
				}

				else {
					//if(dis<0) cross = true;
					if(abs(dis) > abs(target-cur)) dis = cur-target;
					//if(cross) break;
					do {
						--k;
					} while(num[k]==num[k+1]);
				}
			}
		}
		return target+dis;
	}

	/*************** NO. 17 4Sum ***************/
	// this is a timeout solution
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        auto sz = num.size();
        vector<vector<int> > res;
        if(sz<4) return res;
        unordered_map<int, vector<pair<int, int>>> ts;
        for(size_t i=0;i<sz-1;++i){
            for(size_t j=0;j<sz;++j){
                ts[num[i]+num[j]].push_back({i,j});
            }
        }

        vector<int> tmp;
        tmp.reserve(4);
        for(auto &x: ts){
            if(ts.find(target - x.first)!=ts.end()){
                for(auto &p1: x.second){
                    for(auto &p2: ts[target-x.first]){
                        if(p1.first!=p2.first && p1.first!=p2.second && p1.second!=p2.first && p1.second!=p2.second){
                            tmp = {num[p1.first], num[p1.second], num[p2.first], num[p2.second]};
                            sort(tmp.begin(), tmp.end());
                            res.push_back(tmp);
                        }
                    }
                }
            }
        }
        sort(res.begin(), res.end());
        //unordered_set<vector<int> > s(res.begin(), res.end());
        //res.assign(s.begin(), s.end());
        res.erase(unique(res.begin(),res.end()), res.end());
        return res;
    }

    // this is a timeout solution
    vector<vector<int> > fourSum2(vector<int> &num, int target) {
        auto sz = num.size();
        vector<vector<int> > res;
        if(sz<4) return res;
        sort(num.begin(), num.end());
        for(size_t i=0;i<sz-3;++i){
            for(size_t j=i+1;j<sz-2;++j){
                int m=j+1, n=sz-1, tgt=target-num[i]-num[j];
                while(m<n){
                	if(num[i]==-3&&num[j]==0)
                	cout << m << "|" << n << endl;
                    if(2*num[m]>tgt || 2*num[n]<tgt) break;
                    if(num[m]+num[n]==tgt){
                        res.push_back(vector<int>{num[i],num[j],num[m],num[n]});
                        ++m; --n;
                        while(m<n && num[m]==num[m-1]) ++m;
                        while(m<n && num[n]==num[n+1]) --n;
                    }
                    else if(num[m]+num[n]>tgt){
                    	--n;
                        while(m<n && num[n]==num[n+1]) --n;
                    }

                    else //if(num[m]+num[n]<tgt)
                    {
                    	++m;
                        while(m<n && num[m]==num[m-1]) ++m;
                    }
                }
            }
        }
        return res;
    }

    /*************** NO. 19 Remove Nth Node From End of List ***************/
    // this is a slow solution
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head || n<1) return head;
        ListNode *front = head, *back = head;
        while(back && n--){
        	back = back->next;
        }

        if(!back) return head->next;

        while(back->next){
        	front = front->next;
        	back = back->next;
        }

        front->next = front->next->next;
        return head;
    }

    /*************** NO. 20 Valid Parentheses ***************/
    bool isValid(string s) {
    	stack<char> k;
    	for(const auto c: s){
    		if(c=='(' || c=='[' || c=='{') k.push(c);
    		if(c==')' || c==']' || c=='}'){
    			if(k.empty()) return false;
    			if((k.top()=='(' && c==')' )
    					|| (k.top()=='[' && c==']')
    							|| (k.top()=='{' && c=='}')) k.pop();
    			else return false;
    		}
    	}
    	if(k.empty()) return true;
    	return false;
    }

    /*************** NO. 21 Merge Two Sorted Lists ***************/
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	if(l1==nullptr) return l2;
    	if(l2==nullptr) return l1;

    	if((l1->val) <= (l2->val)){
    		ListNode *res = l1, *cur = res;
    		l1 = l1->next;
    		while(l1 && l2){
    			if(l1->val < l2->val){
    				cur->next = l1;
    				l1 = l1->next;
    			}
    			else {
    				cur->next = l2;
    				l2 = l2->next;
    			}
    			cur = cur->next;
    		}
    		if(l1) cur->next = l1;
    		else if(l2) cur->next = l2;
        	return res;
    	}
    	else return mergeTwoLists(l2, l1);
    }

    /*************** NO. 26 Remove Duplicates from Sorted Array ***************/
    // this is a slow solution
    int removeDuplicates(int A[], int n) {
    	if(n<2) return n;

    	int tmp = A[0], j = 0;
    	for(int i = 1; i<n; ++i){
    		while(i<n && A[i]==tmp) ++i;
    		if(i<n){
    			A[++j] = A[i];
    			tmp = A[i];
    		}
    	}
    	return j+1;
    }

    /*************** NO. 27 Remove Element ***************/
    int removeElement(int A[], int n, int elem) {
    	if(n<1) return 0;

    	int j = 0;
    	for(int i = 0; i<n; ++i){
    		while(i<n && A[i]==elem) ++i;
    		if(i<n){
    			A[j++] = A[i];
    		}
    	}
    	return j;
    }

    /*************** NO. 28 Implement strStr() ***************/
    int strStr(char *haystack, char *needle) {

    }

    /*************** NO. 29 Divide Two Integers ***************/
    int divide(int dividend, int divisor) {
    	bool neg = false;
    	int d1 = dividend, d2 = divisor;
    	if(dividend<0){ neg = !neg; d1 = -dividend;}
    	if(divisor<0){neg = !neg; d2 = -divisor;}


    	if(d2==1) return neg?-d1:d1;
    	if(d2==2) return neg?(-d1>>1):(d1>>1);

    }


    /*************** NO. 36 Valid Sudoku ***************/
    bool isValidSudoku(vector<vector<char> > &board) {
        auto szx = board.size();
        if(szx!=9) return false;
        auto szy = board[0].size();
        if(szy!=9) return false;


        for(int i=0; i<szx; ++i){
        	bool b[9] = {false, false, false, false, false, false, false, false, false};
        	for(int j=0; j<szy; ++j){
        		if(board[i][j]=='.') continue;
        		if(b[board[i][j]-49]) return false;
        		b[board[i][j]-49] = true;
        	}

        }

        for(int j=0; j<szy; ++j){
        	bool b[9] = {false, false, false, false, false, false, false, false, false};
        	for(int i=0; i<szx; ++i){
        		if(board[i][j]=='.') continue;
        		if(b[board[i][j]-49]) return false;
        		b[board[i][j]-49] = true;
        	}
        }

        for(int m=0; m<7; m+=3){
        	for(int n=0; n<7; n+=3){
        		bool b[9] = {false, false, false, false, false, false, false, false, false};
                for(int i=0; i<3; ++i){
                	for(int j=0; j<3; ++j){
                		if(board[m+i][n+j]=='.') continue;
                		if(b[board[m+i][n+j]-49]) return false;
                		b[board[m+i][n+j]-49] = true;
                	}
                }
        	}
        }
        return true;
    }

    /*************** NO. 36 Count and Say ***************/
    string countAndSay(int n) {

    }

    /*************** NO. 58 Length of Last Word ***************/
    // does not work with " a".
    int lengthOfLastWord(const char *s) {
        if(!*s) return 0;
        if(!*(s+1)) return static_cast<int>(*s!=' ');

    	int a=0, b=0, i=0;

    	while(*(s+1)){

    		if(*s==' ' && *(s+1)!=' ') a = i;
    		//if(*s!=' ' && *(s+1)==' ') b = i;
    		if(*s!=' ') b = i;
    		++i; ++s;
    	}
    	//if(*(s-1)!=' ') b = i;

    	cout << a << "|" << b << endl;
    	return b-a;
    }

    /*************** NO. 66 Plus One ***************/
    vector<int> plusOne(vector<int> &digits) {
    	auto sz = digits.size();
    	if(!sz) return {};

    	vector<int> res; res.reserve(sz+1);
    	int inc = 1, x;
    	auto it=digits.rbegin(), end=digits.rend();
    	for(; it!=end; ++it){
    		x = *it + inc;
    		res.push_back(x%10);
    		if(x<10) break;
    	}

    	if(x>=10) res.push_back(1);
    	else res.insert(res.end(), it+1, end);
    	std::reverse(res.begin(), res.end());

    	return res;
    }

    /*************** NO. 67 Add Binary ***************/
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

    /*************** NO. 70 Climbing Stairs ***************/
    int climbStairs(int n) {
    	++n;
        if (n < 2) return n;
        if (n == 2) return 1;
        int k = n / 2;
        int a = climbStairs(k + 1);
        int b = climbStairs(k);
        if (n % 2 == 1)
            return a * a + b * b;
        else
            return b * (2 * a - b);
    }

    string addBinary(string a, string b) {
    	if(a=="") return b;
    	if(b=="") return a;

    	auto sza = a.size(), szb = b.size();
    	auto sz = min(sza, szb);

    	string res; int inc = 0, i = 1;
    	for(;i<=sz;++i){
    		res = bitAdd(a[sza-i], b[szb-i], inc) + res;
    	}

    	for(;i<=sza;++i){
    		res = bitAdd(a[sza-i], '0', inc) + res;
    	}

    	for(;i<=szb;++i){
    	    res = bitAdd('0', b[szb-i], inc) + res;
    	}

    	if(inc) res = '1' + res;
    	return res;
    }

    /*************** NO. 64	Minimum Path Sum ***************/
    int minPathSum(vector<vector<int> > &grid) {
        size_t m = grid.size();
        if(m==0) return 0;
        size_t n = grid[0].size();
        if(n==0) return 0;
        int res = 0;

        if(m==1){
            for(auto &x: grid[0]) res+=x;
            return res;
        }

        if(n==1){
            for(auto &x: grid) res+=x[0];
            return res;
        }

        //vector<vector<int> > tmp1 = std::move(grid.begin(), grid.end()-1);

        vector<vector<int> > tmp1(grid.begin(), grid.end()-1);
        vector<vector<int> > tmp2(grid.begin(), grid.end());
        for(auto &x: tmp2) x.resize(n-1);
        return min(minPathSum(tmp1), minPathSum(tmp2)) + grid[m-1][n-1];
    }

    /*************** NO. 74	Search a 2D Matrix ***************/
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size();
        if(m==0) return false;
        int n = matrix[0].size();
        if(n==0) return false;

        if(matrix[0][0]>target || matrix[m-1][n-1]<target) return false;
        if(matrix[0][0]==target || matrix[m-1][n-1]==target) return true;

        int x=0, y = m*n-1, t, a, b;
        while(x<y){
            t = (x+y)/2;
            a = t/n;
            b = t%n;
            if(matrix[a][b]==target) return true;
            else if(matrix[a][b]<target) x = t>x?t:(x+1);
            else y = t<y?t:(y-1);
        }
        return false;
    }

//    string addBinary(string a, string b) {
//        if(a=="0" && b=="0") return "0";
//        int x = a.size(), y = b.size();
//        if(x<=y){
//            if(x==0) return b;
//            string s = "";
//            cout << s << endl;
//            int inc = 0;
//            /*
//            for(int i=y-1; i>=0; --i){
//                if(i-y+x>=0) s = bitAdd(a[i-y+x], b[i], inc) + s;
//                else s = bitAdd('0', b[i], inc) + s;
//            }
//            if(inc) s = "1" + s;
//            return s;
//            */
//
//            int i = x, j = y;
//            while(i){
//                s = bitAdd(a[i-1], b[j-1], inc) + s;
//                --i; --j;
//            }
//
//            while(j){
//                s = bitAdd('0', b[j-1], inc) + s;
//                --j;
//            }
//            return s;
//        }
//        return addBinary(b, a);
//    }

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

//	ListNode *removeNthFromEnd(ListNode *head, int n) {
//		if(n<=0 || !head) return head;
//		/* special case */
//		if(n==1 || !head->next) return NULL;
//		ListNode *t1 = head, *t2 = head;
//
//		int i=1;
//		for(;i<=n && t2->next; ++i){
//			t2 = t2->next;
//		}
//
//		if(i==n-1) return head->next;
//
//		while(t2){
//			t1=t1->next;
//			t2=t2->next;
//		}
//
//		t1->next = t1->next->next;
//		return head;
//	}


//	int strStr(char *haystack, char *needle) {
//        if(!haystack || haystack=='\0') return -1;
//		int res;
//		char *p;
//		for(p=needle, res=0; p!='\0' && haystack!='\0'; ++haystack){
//			while(p!='\0' && haystack!='\0' && *p==*haystack){
//				++p; ++haystack; ++ res;
//			}
//
//			if(!p) return res;
//			if(!haystack) return -1;
//		}
//		return -1;
//	}

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

//	string say(const string &s){
//		int cnt = 1;
//		char x = s[0];
//		string res = "";
//
//		for(size_t i=1; i<s.size(); ++i){
//			if(s[i]==x){
//				++cnt;
//			}
//			else{
//				res += int2str(cnt) + x;
//				x = s[i];
//				cnt = 1;
//			}
//		}
//
//		res += int2str(cnt) + x;
//		return res;
//	}
//
//	string countAndSay(int n) {
//		if(n==1) return "1";
//		else return say(countAndSay(n-1));
//	}

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

    int numDecodings(string s) {
        auto sz = s.size();
        if(sz<1) return 0;
        if(sz<2){
            if(s[0]<='9' && s[0]>='1') return 1;
            else return 0;
        }

        int a, b=1;
        a = (s[0]=='0'?0:1);

        for(size_t i=1;i<sz;++i){
            if((s[i-1]=='1' && s[i]>='1' && s[i]<='9') || (s[i-1]=='2' && s[i]>='1' && s[i]<='6')){
                a = a + b;
                b = a - b;
            }

            else if((s[i-1]=='1' || s[i-1]=='2') && s[i]=='0'){
                swap(a, b);
            }

            else if(s[i]>='1'&&s[i]<='9'){
                //a = a;
                b = a;
            }

            else return 0;
        }
        return a;
    }

//    vector<vector<int> > fourSum(vector<int> &num, int target) {
//        auto sz = num.size();
//        vector<vector<int> > res;
//        if(sz<4) return res;
//        unordered_map<int, vector<pair<int, int>>> ts;
//        for(size_t i=0;i<sz-1;++i){
//            for(size_t j=0;j<sz;++j){
//                ts[num[i]+num[j]].push_back({i,j});
//            }
//        }
//
//        vector<int> tmp;
//        tmp.reserve(4);
//        for(auto &x: ts){
//            if(ts.find(target - x.first)!=ts.end()){
//                for(auto &p1: x.second){
//                    for(auto &p2: ts[target-x.first]){
//                        if(p1.first!=p2.first && p1.first!=p2.second && p1.second!=p2.first && p1.second!=p2.second){
//                            tmp = {num[p1.first], num[p1.second], num[p2.first], num[p2.second]};
//                            sort(tmp.begin(), tmp.end());
//                            res.push_back(tmp);
//                        }
//                    }
//                }
//            }
//        }
//        sort(res.begin(), res.end());
//        //unordered_set<vector<int> > s(res.begin(), res.end());
//        //res.assign(s.begin(), s.end());
//        res.erase(unique(res.begin(),res.end()), res.end());
//        return res;
//    }

//    vector<vector<int> > fourSum2(vector<int> &num, int target) {
//        auto sz = num.size();
//        vector<vector<int> > res;
//        if(sz<4) return res;
//        sort(num.begin(), num.end());
//        for(size_t i=0;i<sz-3;++i){
//            for(size_t j=i+1;j<sz-2;++j){
//                int m=j+1, n=sz-1, tgt=target-num[i]-num[j];
//                while(m<n){
//                	if(num[i]==-3&&num[j]==0)
//                	cout << m << "|" << n << endl;
//                    if(2*num[m]>tgt || 2*num[n]<tgt) break;
//                    if(num[m]+num[n]==tgt){
//                        res.push_back(vector<int>{num[i],num[j],num[m],num[n]});
//                        ++m; --n;
//                        while(m<n && num[m]==num[m-1]) ++m;
//                        while(m<n && num[n]==num[n+1]) --n;
//                    }
//                    else if(num[m]+num[n]>tgt){
//                    	--n;
//                        while(m<n && num[n]==num[n+1]) --n;
//                    }
//
//                    else //if(num[m]+num[n]<tgt)
//                    {
//                    	++m;
//                        while(m<n && num[m]==num[m-1]) ++m;
//                    }
//                }
//            }
//        }
//        return res;
//    }

    int maxProduct(int A[], int n) {
    	if(n<=0) return 0;
    	if(n==1) return A[0];
        int globalmax = A[0], localmin = A[0], localmax=A[0];
        for(int i=1;i<n;++i){
        	int localcopy(localmax);
        	localmax = max(max(localmax*A[i], A[i]), localmin*A[i]);
        	localmin = min(min(localcopy*A[i], A[i]), localmin*A[i]);
        	globalmax = max(globalmax, localmax);
        }
        return globalmax;
    }
};

template<class T>
void print(const T& t){
	for(const auto &x: t){
		cout << x << "|";
	}
	cout << endl;
}

//template<>
void printVector(const vector<vector<int>>& res){
	for_each(res.begin(), res.end(), [](const vector<int>& v){
		for_each(v.begin(), v.end(), [](const int &i){
			cout << i << "|";
		});
		cout << endl;
		}
	);
}

void printList(ListNode* head){
	while(head!=nullptr){
		cout << head->val << "|";
		head = head->next;
	}
	cout << endl;
}

int main(){
    Solution s;

    /****************** NO.1 TWO SUM ******************/
//    vector<int> numbers{2, 7, 11, 15};
//    int target = 9;
//
//    vector<int> res = s.twoSum(numbers, target);
//    print<vector<int>>(res);

    /****************** NO.2 ADD TWO NUMBERS ******************/
//    ListNode a{2}, b{4}, c{3};
//    ListNode x{5}, y{6}, z{6};
//
//    a.next = &b;
//    b.next = &c;
//    x.next = &y;
//    //y.next = &z;
//
//    ListNode *res = s.addTwoNumbers(&a, &x);
//    printList(res);

    /*************** NO. 4 Median of Two Sorted Arrays ***************/
//    int A[10], B[20];
//    for(int i= 0; i<10; ++i) A[i] = rand();
//    for(int i= 0; i<10; ++i) B[i] = rand();
//    vector<int> x;
//    x.reserve(300);
//    x.assign(A, A+10);
//    copy(B, B+20, inserter(x, x.end()));
//    print(A);
//    print(B);
//    print(x);
//
//    nth_element(x.begin(), x.begin()+x.size()/2, x.end());
//    cout << "Median of the vector is: " << x[x.size()/2] << endl;
//    cout << "Median of the vector is: " << s.findMedianSortedArrays(A, 10, B, 20) << endl;

    /*************** NO. 13 Roman to Integer ***************/
//    string a{"MCMLIV"}, b{"MCMXC"}, c{"MMXIV"}, d{"DCXXI"};
//    cout << s.romanToInt(a) << endl;
//    cout << s.romanToInt(b) << endl;
//    cout << s.romanToInt(c) << endl;
//    cout << s.romanToInt(d) << endl;

    /*************** NO. 15 Longest Common Prefix ***************/
//    string a = "AAA", b = "AAA";
//    vector<string> strs{a, b};
//    cout << s.longestCommonPrefix(strs) << endl;


    /*************** NO. 15 3Sum ***************/
//    vector<int> num{7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
//    auto res = s.threeSum(num);
//    print(res);
//
//    cout << res.size() << endl;
//	sort(res.begin(), res.end());
//	res.erase(unique(res.begin(), res.end()), res.end());
//    cout << res.size() << endl;

    /*************** NO. 16 3Sum Closest ***************/
//    vector<int> num{1,2,4,8,16,32,64,128};
//    int target = 82;
//    cout << s.threeSumClosest(num, target) << endl;

    /*************** NO. 17 4Sum ***************/
//    vector<int> num{1, 0, -1, 0, -2, 2};
//    int target = 0;
//    auto res = s.fourSum(num, target);
//    cout << res.size() << endl;
//    printVector(res);

    /*************** NO. 19 Remove Nth Node From End of List ***************/
//    ListNode a{1}, b{4}, c{9};
//    ListNode x{2}, y{3}, z{7};
//
//    a.next = &b;
//    b.next = &c;
//    x.next = &y;
//    y.next = &z;
//
//    printList(s.removeNthFromEnd(&a, 1));
//    printList(s.removeNthFromEnd(&a, 0));
//    printList(s.removeNthFromEnd(&a, 5));
//    printList(s.removeNthFromEnd(&a, 6));

    /*************** NO. 20 Valid Parentheses ***************/
//    string str = "()[]{}";
//    if(s.isValid(str)) cout << "this is a valid string. " << endl;
//    else cout << "this is not a valid string. " << endl;

    /*************** NO. 21 Merge Two Sorted Lists ***************/
//    ListNode a{1}, b{4}, c{9};
//    ListNode x{2}, y{3}, z{7};
//
//    a.next = &b;
//    b.next = &c;
//    x.next = &y;
//    y.next = &z;
//    printList(&a);
//    printList(&x);
//    printList(s.mergeTwoLists(&a, &x));

    /*************** NO. 26 Remove Duplicates from Sorted Array ***************/
    //int A[10] = {1, 1, 3, 4, 6, 6, 6, 6, 10, 12};
//    int A[2] = {1, 1};
//    print(A);
//    int len = s.removeDuplicates(A, 2);
//    for(int i = 0; i<len; ++i) cout << A[i] << "|";
//    cout << endl;

    /*************** NO. 27 Remove Element ***************/
//    int A[12] = {1, 1, 3, 4, 6, 6, 7, 8, 6, 6, 10, 12};
//    print(A);
//    int len = s.removeElement(A, 12, 6);
//    for(int i = 0; i<len; ++i) cout << A[i] << "|";
//    cout << endl;

    /* Decode Ways */
    //string str = "10";

    //cout << s.numDecodings(str) << endl;


    /*************** NO. 36 Valid Sudoku ***************/
//    vector<vector<char>> x{{'.','8','7','6','5','4','3','2','1'}
//    	,{'2','.','.','.','.','.','.','.','.'}
//    	,{'3','.','.','.','.','.','.','.','.'}
//    	,{'4','.','.','.','.','.','.','.','.'}
//    	,{'5','.','.','.','.','.','.','.','.'}
//    	,{'6','.','.','.','.','.','.','.','.'}
//    	,{'7','.','.','.','.','.','.','.','.'}
//    	,{'8','.','.','.','.','.','.','.','.'}
//    	,{'9','.','.','.','.','.','.','.','.'}
//    	};
//    cout << s.isValidSudoku(x) << endl;

    /*************** NO. 58 Length of Last Word ***************/
//    const char *a = "Hello world", *b = "   ", *c = "Hello world  ", *d = "a", *e = " a";
//    cout << s.lengthOfLastWord(a) << endl;
//    cout << s.lengthOfLastWord(b) << endl;
//    cout << s.lengthOfLastWord(c) << endl;
//    cout << s.lengthOfLastWord(d) << endl;
//    cout << s.lengthOfLastWord(e) << endl;

    /*************** NO. 66 Plus One ***************/
//    vector<int> digits1{1,2,3,4,5,6,7,8,9}, digits2={9}, digits3={9, 9, 9};
//    vector<int> res1 = s.plusOne(digits1);
//    vector<int> res2 = s.plusOne(digits2);
//    vector<int> res3 = s.plusOne(digits3);
//    print(res1); print(res2); print(res3);

    /*************** NO. 67 Add Binary ***************/
//    string a = "11", b = "1";
//    cout << s.addBinary(a, b) << endl;

    /*************** NO. 70 Climbing Stairs ***************/
    cout << s.climbStairs(10) << endl;

    /*************** 18. Four Sum ***************/
//    vector<int> num{-3,-2,-1,0,0,1,2,3};
//    int target = 0;
//    auto res = s.fourSum2(num, target);
//
//    for_each(res.begin(), res.end(), [](vector<int> &v){for_each(v.begin(), v.end(),
//    		[](const auto& x){cout << x << "|";}); cout << endl;});

    /*************** 152. Maximum Production Subarray ***************/
//    int A[] = {1,-2,3,4};
//    cout << s.maxProduct(A, 4) << endl;
    /*
    vector<int> x{1,2,3};
    cout << s.findMin(x) << endl;
    */

    /*
    string v = "01.1";
    int x, y;

    s.parseVersion(v, x, y);
    cout << s.numDigits(y) << endl;

    cout << x << "|" << y << endl;
    //int x = s.atoi("-1");
    //cout << x << endl;
	*/

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
    return 0;
}
