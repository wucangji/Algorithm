class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==0) return s;
        string longest = s.substr(0,1);
        for(int i=0;i<n-1;i++){
            string p1 = expandfromcenter(s,i,i);
            if(p1.size()>longest.size()) longest = p1;
            
            string p2 = expandfromcenter(s,i,i+1);
            if(p2.size()>longest.size()) longest = p2;
        }   
        return longest;
    }
    
    string expandfromcenter(string s, int c1, int c2){
        int l = c1, r=c2;
        int n = s.size();
        while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;   // expand
        }
        return s.substr(l+1,r-l-1) ;  // 左右各减去一位
    }
    
};