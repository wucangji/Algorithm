class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length() , n2 = s2.length(), n3 = s3.length();
        if(n1+n2!=n3) return false;
        
        vector<vector<bool> > ta(n1+1,vector<bool>(n2+1));
        ta[0][0] = true;
        for(int i=1;i<=n2;i++){
            if(ta[0][i-1] && s2[i-1] == s3[i-1]) ta[0][i] =true;   // 初始化第一行 ta
            //else break;
        }
        
        for(int i=1;i<=n1;i++){
            if(ta[i-1][0]  && s1[i-1]==s3[i-1])   ta[i][0] = true;  // 初始化第一列
            for(int j=1;j<=n2;j++){
                if(ta[i][j-1] && s2[j-1] == s3[i+j-1])  ta[i][j] = true;    ///// 不是看物理意义，直接看dP 含义  i指S1，j指S2
                else if(ta[i-1][j] && s1[i-1] == s3[i+j-1]) ta[i][j] = true;
            }
        }
        return ta[n1][n2];
    }
};