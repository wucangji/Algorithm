class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows<=1) return s;  // remember to check the row number
        string result;
        int zigsize = 2*nRows-2;
        for(int i=0;i<nRows;i++){
            for(int base=i;;base+=zigsize){
                if(base>=s.size()) break;      // remember > =  !!
                result.append(1,s[base]);
                if(i>0 && i<nRows-1){              //  not  || should &&　　
                    int mediate = base+zigsize-2*i;
                    if(mediate<s.size()) 
                        result.append(1,s[mediate]);
                }
            }
        }
        return result;
    }
};