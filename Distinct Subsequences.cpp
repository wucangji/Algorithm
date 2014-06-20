class Solution {
public:
    int numDistinct(string S, string T) {
        vector<int> f(T.size()+1,0);
        f[0]=1;
        for(int i = 0 ;i<S.size(); i++){
            for(int j=T.size()-1;j>=0; j--){    // remember to start from the end
                f[j+1] += S[i]==T[j]? f[j] : 0;  
            }
        }
        return f[T.size()];
    }
};