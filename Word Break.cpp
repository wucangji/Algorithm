class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n=s.size();
        vector<bool> f(s.size()+1);
        f[0] = true;
        for(int i=1;i<=n;i++){
            for(int k = 0; k<i;k++){
                f[i] = f[k] && dict.count(s.substr(k,i-k));  // this sentence is important, no need to add a junk node in the front
                if(f[i]) break;
            }
        }
        return f[s.size()];
    }
};