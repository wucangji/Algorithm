class Solution {
public:

    void reverse(vector<int> &num, int i, int j){
        while(i<j){
            swap(num[i++],num[j--]);
        }
    }
    // should use this verse, swap is std
    
    void nextPermutation(vector<int> &num) {
        for(int i= num.size()-2;i >= 0;i--){
            if(num[i]<num[i+1]){
                for(int j=num.size()-1;j>i;j--){
                    if(num[j]>num[i]){
                        int temp = num[j];
                        num[j] = num[i];
                        num[i] = temp;
                        break;  // do not forget to break;
                    }
                }
                
                reverse(num,i+1,num.size()-1);
                return;   // need to return ///~~~!
            }
        }
        // if cannot find the ascending;
        reverse(num,0,num.size()-1);
        
    }
};