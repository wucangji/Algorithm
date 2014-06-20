class Solution {
public:
    int atoi(const char *str) {
        int n = strlen(str);
        int i = 0;
        int sign = 1;
        int result = 0;
        while(i < n && str[i] == ' ') i++;
        if(str[i] == '+' || str[i] == '-'){    // should compare + - at the same time, otherwise    +- 45 is right
            if(str[i] == '-') sign = -1;
            i++;
        } 
        
        for(;i<n;i++){
            if(str[i] > '9' || str[i] < '0') break;
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i]-'0') % 10 > INT_MAX % 10)) {
                // should be INT_MAX /  10 
                return sign == 1 ? INT_MAX: INT_MIN;
            }
            result = result * 10 + str[i]-'0';
        }
        
        return result * sign;
    }
};