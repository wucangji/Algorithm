class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int sLen = S.size();
        int lLen = L.size();
        vector<int> result;
        if(lLen < 1) return result;
        int len = L[0].size();
        
        unordered_map<string,int> LMap;
        unordered_map<string,int> countMap;
        
        string index;
        for(auto x: L) LMap[x]++;   // from 0->1
        
        for(int d=0;d<len;d++){
            for (int i=d;i<=sLen-lLen*len;i+=len){
                int start = i;
                index = S.substr(i,len);
                while(LMap.count(index) && i<=sLen-len){
                    countMap[index]++;
                    if(countMap[index]>LMap[index]){
                        string sTemp = S.substr(start,len);
                        while(sTemp != index){
                            start += len;
                            sTemp = S.substr(start,len);
                            countMap[sTemp]--;
                        }
                        countMap[sTemp]--;
                        start += len;
                    }
                    
                    i+=len;
                    if((i-start)/len == lLen){
                        result.push_back(start);
                        string sTemp = S.substr(start,len);
                        countMap[sTemp]--;
                        start+=len;
                    }
                    index = S.substr(i,len);
                }
                countMap.clear();
            }
        }
        return result;
        
    }
};