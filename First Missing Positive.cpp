
// method 1 sort then detect

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // solution 1 sort
        sort(A,A+n);  //nlogn
        int i = 0;
        while(A[i]<=0 && i<n) i++;  //skip all the negative
        int k = 0;
        for(;i<n;i++){
            if(i>0 && A[i] == A[i-1]) continue;
            if((A[i]-k)!=1) return k+1;
            k = A[i];
        }
        return k+1;
    }
};



// method 2  bucket sort.    subscript = I

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        int i=0;
        while(i<n){
            if(A[i]>=0 && A[i]< n && A[i]!=A[A[i]]) swap(A[i],A[A[i]]);  //  not A[i]!= i; // 若超出A  A[超] = 0 ；
            else i++;   // cannot lost the else~~!!
        }
        int k =1;
        while(A[k] == k && k<n) k++;
        if(n==0 || k<n)  return k;
        else return A[0]==k? k+1:k;
    }
};