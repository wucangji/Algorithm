class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        
        if(matrix.empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> L(n,0);
        vector<int> R(n,n);
        vector<int> H(n,0);
        

        int area =0;
        for(int i=0; i<m; i++){
            int left = 0;
            int right = n;  // each line should start from 0 and n
            
            for(int j=0;j<n; j++){
                //scan from the left to right
                if(matrix[i][j] == '1'){
                    H[j]++;
                    L[j]=max(L[j],left);   // left border should sue max.
                }
                else{
                    left=j+1;
                    L[j]=0;H[j]=0;R[j]=n;
                }
            }
            for(int j=n-1;j>=0;j--){
                //scan from right to left
                if(matrix[i][j] == '1'){
                    R[j] = min(R[j],right);   // compare with right
                    area=max(area,H[j]*(R[j]-L[j]));
                }
                else{
                    right = j;
                }
            }   
      
        }
        return area;
    }
};