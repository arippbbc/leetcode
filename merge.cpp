class Solution {
public:
    void shift(int A[], int x, int &y){
        if(x<y){
                for(int i=y; i>x; --i){
                        A[i] = A[i-1];
                }
        }
        ++y;
    }

    void merge(int A[], int m, int B[], int n) {
        if(n==0) return;
        int i=0, j=0;
        while(i<m && j<n){
            if(A[i]<=B[j]) ++i;
            else{
                shift(A, i, m);
                A[i++] = B[j++];
            }
        }

        if(m==0) i = 0;
        //else if(i==m) ++i;
        while(j<n){
            A[i++] = B[j++];
        }
    }

    void print(int A[], int m){
        for(int i=0; i<m; ++i){
            cout << A[i] << "|";
        }
        cout << endl;
    }
};
