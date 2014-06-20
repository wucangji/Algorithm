class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();
        vector<int> increment(n,0);
        int inc = 1;
        for(int i = 1;i<n;i++){
            if(ratings[i]>ratings[i-1]) increment[i]=max(increment[i], inc++);   // I compare with the left
            else inc = 1;
        }
        
        for(int i=n-2, inc = 1;i>=0;i--){
            if(ratings[i]>ratings[i+1]) increment[i]=max(increment[i], inc++); //  i  compare with the right
            else inc = 1;
        }
        
        return accumulate(increment.begin(),increment.end(),n);
    }
};