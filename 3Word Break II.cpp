class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // http://zhaohongze.com/wordpress/2013/12/10/leetcode-word-break-ii/
        vector<string> temp;
        vector<vector<string> > sens(s.size()+1,temp);
        sens[0].push_back("a");
        for(int i=0;i<s.size();i++){
            if(!sens[i].size()) continue;
            for(string word:dict){
                if(s.substr(i,word.size())==word) {
                    sens[i+word.size()].push_back(word);
                } 
            }
        }
        vector<string> result;
        vector<string> curSen;
        if(sens[s.size()].size()){
            buildResult(result,sens,s.size(),curSen);
        }
        return result;
    }
    
    void buildResult(vector<string> &result,vector<vector<string> > &sens,int cur, vector<string> &curSen){
        if(cur == 0){
            string temp;
            for(int i=curSen.size()-1;i>=0;i--){
                temp += curSen[i];
                if(i!=0) temp+=" ";
            }
            result.push_back(temp);
            return;
        }
        
        for(int i=0;i<sens[cur].size();i++){
            curSen.push_back(sens[cur][i]);
            buildResult(result,sens,cur-sens[cur][i].size(),curSen);
            curSen.pop_back();
        }
    }
};