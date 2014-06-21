class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;
        if(num.size()<3) return result;
        sort(num.begin(),num.end());
        const int target = 0;
        
        int n = num.size();
        for(int a=0; a < n-2 ; ++a){
            int b=a+1;
            int c=n-1;  
            
            while(b<c){
                if(num[a]+num[b]+num[c] < target){
                    b++;
                }
                else if(num[a]+num[b]+num[c] > target){
                    c--;
                }else{
                    result.push_back({num[a],num[b],num[c]});
                    b++;
                    c--;
                }
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());  // 10 20 30 20 10 ?  ?  ?  ?
        return result;
    }
};

// cannot pass the time limit



try another one 


class Solution {
public:
    vector<vector <int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
     vector<int> res_m(3);
        vector< vector<int> > res;
        vector<int>::iterator it1,it2,it3,iend;
         
        sort(num.begin(),num.end());
        if(num.size()>=3){
            iend = num.end();
            it1 = num.begin();
            bool f1 = false;
            for ( ;it1!=iend-2;++it1){
                if(f1 && *it1==*(it1-1)) {continue;}
                f1 = true;
                bool f2 = false;
                bool f3 = false;
                it3 = iend-1;
                it2 = it1+1;
                while (it2!=it3){
                     
                    if(f3 && *it3==*(it3+1)) { it3 = it3 -1 ;continue;}
                    if(f2 && *it2==*(it2-1)) { it2 = it2 +1 ;continue;}
                                     
                    if (*it1 + *it2 + *it3==0){
                        res_m.at(0)=*it1;
                        res_m.at(1)=*it2;
                        res_m.at(2)=*it3;
                        res.push_back(res_m);
                    }
                    if (*it1 + *it2 + *it3 >0){
                        it3=it3-1;
                        f3 = true;
       
                    }else{
                        it2=it2+1;
                        f2 = true;
                    }
                     
                }
                 
            }
        }
        return res;
    }
};