class Solution {
public:
    string getPermutation(int n, int k) {
        //http://fisherlei.blogspot.com/2013/04/leetcode-permutation-sequence-solution.html
        vector<int> num(n);
        int factorial = 1 ;
        for(int i=0; i<n; i++){
            num[i] = i+1;
            factorial *= (i+1);
        }
        k-- ;
        string result;
        for(int i=0;i<n;i++){
            factorial /= (n-i);
            int choosed = k / factorial;
            result.push_back(num[choosed] + '0');
            for(int j = choosed;j<n-1;j++){
                num[j]=num[j+1];
            }
            k=k%factorial; //  k should be changed  !! 
        }
        return result;
    }
};