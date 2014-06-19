class Solution {
public:
    int jump(int A[], int n) {
        int result = 0;
        int cur = 0;
        int last = 0;
        for(int i=0; i<n; i++){
            if(last>=n) return result;
            if(i>last){
                result++;
                last = cur;
            }
            cur = max(cur,i+A[i]);
        }

        return result;        
    }
};