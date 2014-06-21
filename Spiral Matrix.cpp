class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> result;
        int n = matrix.size();
        if(n==0) return result;
        int m = matrix[0].size();
        int beginx=0, beginy=0;
        int endx=m-1,endy=n-1;
        while(1){
        for(int j=beginx;j<=endx;j++){
            result.push_back(matrix[beginy][j]);
        }
        if(++beginy>endy) break;
        for(int i=beginy;i<=endy;i++){
            result.push_back(matrix[i][endx]);
        }
        if(--endx<beginx) break;
        for(int j=endx;j>=beginx;j--){
            result.push_back(matrix[endy][j]);
        }
        if(--endy<beginy) break;
        for(int i=endy;i>=beginy;i--){
            result.push_back(matrix[i][beginx]);
        }
        if(++beginx>endx) break;
        }
        return result;
    }
};