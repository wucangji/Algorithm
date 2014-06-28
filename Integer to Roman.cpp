class Solution {
public:
    string intToRoman(int num) {
        int digits[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};  
        string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}; 
        string result;
        int i =0 ;
        while(num>0){
            int times = num/digits[i];
            num=num % digits[i];
            for(int j=0;j<times;j++){
                result += symbols[i];
            }
            i++;
        }
        return result;
    }
};


//  900    400   90  40 9  4 记住