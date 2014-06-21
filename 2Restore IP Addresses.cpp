class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
       vector<string>result;
       string path;
       dfs(s,0,0,path,result);
       return result;
    }
    
private:
    void dfs(string s,int step,int start, string path, vector<string> &result){
        if(start == s.size() && step == 4){ // find a possible solution
            path.resize(path.size()-1);
            result.push_back(path);
            return;
        }
        // cut some branch
        if((s.size()-start)>(4-step)*3) return;  // too many 
        if((s.size()-start)<(4-step))  return; // not enough
        int num = 0;
        for(int i=start;i<start+3;i++){
            num = 10*num+s[i]-'0';
            if(num<=255){
                path += s[i];
                dfs(s,step+1,i+1,path+'.',result);
            }
            if(num == 0) break;
        }
        
        
        
    }
};