class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // http://blog.csdn.net/kenden23/article/details/17611675
        vector<vector<string> > rs;
        unordered_map<string,vector<string> > ump_sv;
        dict.erase(start);
        dict.erase(end);
        
        vector<string> qu[2];
        set<string> sst;
        qu[0].push_back(start);
        bool idx = false;
        bool finished = false;
        while(!qu[idx].empty()){
            while(!qu[idx].empty()){
                string s = qu[idx].back();
                for(int i=0;i<s.size();i++){
                    char a = s[i];
                    for(char az='a';az<='z';az++){
                        s[i]=az;
                        if(s == end){
                            finished = true;
                            ump_sv[s].push_back(qu[idx].back());
                        }else if(dict.count(s)){
                            ump_sv[s].push_back(qu[idx].back());
                            qu[!idx].push_back(s);
                        }
                    }
                    s[i]= a;
                }//end while2
                qu[idx].pop_back();
            }
            if(finished) break;
            idx=!idx;
            sst.clear();
            sst.insert(qu[idx].begin(),qu[idx].end());
            qu[idx].assign(sst.begin(),sst.end());
            
            for(auto x:qu[idx]) dict.erase(x);
        }//end while
        if(!ump_sv.count(end)) return rs; // return NULL
        vector<string>tmp (1,end);
        constructorLadder(rs,tmp,ump_sv,start,end);
        return rs;
    }
    
    void constructorLadder(vector<vector<string> >&rs,vector<string> &tmp,
    unordered_map<string,vector<string> > &ump_sv,string &start,string &cur){
        if(cur == start){  // mean that we can find
            //reverse(tmp.begin(),tmp.end());
            //rs.push_back(tmp);    // 这里和下面有啥区别
            rs.push_back(tmp);  
            reverse(rs.back().begin(), rs.back().end()); 
            return;
        }
        vector<string> v= ump_sv[cur];
        for(int i=0;i<v.size();i++){
            tmp.push_back(v[i]);      // 是不是这里的push 可能重复了之前访问过的值，所以慢了还容易错。
            constructorLadder(rs, tmp, ump_sv, start, v[i]);  
            tmp.pop_back();   // 一个个试试，不成功就返回上一个状态下面接着来。
        }
    }
    
};