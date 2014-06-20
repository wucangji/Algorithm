class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if(n<2) return 0;
        vector<int> f(n,0);      // should be n, not n-1
        vector<int> g(n,0);
        
        for(int i=1, minprice=prices[0] ;i<n;i++){
            minprice = min(minprice,prices[i]);
            f[i] = max(f[i-1],prices[i]-minprice); 
        }
        
        for(int i=n-2, maxprice=prices[n-1];i>=0;i--){
            maxprice = max(maxprice,prices[i]);
            g[i] = max(g[i+1],maxprice-prices[i]);
        }
        int result=0;
        for(int i=0;i<n;i++){
            result = max(result,f[i]+g[i]);
        }
        return result;
    }
};

// we can reduce the last for, try it.