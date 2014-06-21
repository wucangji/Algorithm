class Solution {
public:
    int sqrt(int x) {
        if(x<2) return x;   // the corner case
        int left=1, right = x/2;
        int last_mid;
        while(left<=right){
            int mid = (left+right)/2;
            
            if(x/mid > mid) {
                left = mid+1;
                last_mid = mid;    // lastmid should be inside the left part
            }
            else if(x/mid < mid) right = mid-1;
            else return mid;
        }
        return last_mid;
    }
};