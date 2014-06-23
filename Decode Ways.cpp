class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        int prev = 1;
        int cur = 1 ;
        int mid = 1 ;
        for(int i = 1; i< s.size();i++){
            cur = s[i] == '0'? 0 :mid ;
            if( s[i-1] == '1' || (s[i-1] == '2' && s[i] <= '6'))  cur +=prev; 
            prev = mid;
            mid = cur;
        }
        return cur;
    }
};

//method 2

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0 || s[0] == '0') return 0;
        int prev = 0;
        int cur = 1 ;
        
        for(int i = 1; i<= s.size();i++){   // MUST be  <=   // i-1 mean itself    i-2 mean the number before
            if(s[i-1] == '0') cur = 0 ;
            if( i<2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))  prev = 0; 
            int temp = cur;
            cur = cur+prev;
            prev = temp;
        }
        return cur;
    }
};