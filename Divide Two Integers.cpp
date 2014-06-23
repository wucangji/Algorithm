class Solution {
public:
    int divide(int dividend, int divisor) {
        long long a = abs((long long)dividend);   // keep subtract a 
        long long b = abs((long long)divisor);
        int result = 0;
        while(a>=b){
            int count = 0;
            while(a>= b<<count){
                result += 1<<count;
                a -= b<<count;
                count++;
            }
        }
        return (dividend>0)^(divisor>0)? -result:result;
    }
};