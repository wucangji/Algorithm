class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack <int> s;
        height.push_back(0);
        int result = 0;
        for(int i=0;i<height.size();){
            if(s.empty() || height[i] > height[s.top()]){    // s store the index!!
                s.push(i++);
            }
            else{
                int temp = s.top();
                s.pop();
                result = max(result,height[temp]*(s.empty()? i : i-s.top()-1));    // height[temp] is not highest one, the one behind it
            }
        }
        return result;
    }
};