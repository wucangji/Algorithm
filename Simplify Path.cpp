class Solution {
public:
    string simplifyPath(string path) {
        string res;
        res.push_back('/');
        for(int i=1;i<path.size();i++){
            string ts = "";
            while (i<path.size() && path[i]!='/'){
                ts += path[i];
                i++;
            }
            if(ts == "..") {
                if(!res.empty() && res.back()=='/') res.pop_back();
                while(!res.empty() && res.back()!='/') res.pop_back();  //  pop 到/ 为止
                if(res.empty()) res.push_back('/');
            }
            else if(ts != "."){
                res.append(ts);
                if(ts!="")res.push_back('/');  // ts is possible to be null
            }
            
        }
        if(!res.empty() && res.back() == '/') res.pop_back();
        if(res.empty()) return "/";
        return res;
    }
};