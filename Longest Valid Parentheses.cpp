class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int num = 0;
        int last =-1;
        for(int i =0;i<n;i++){
            if(s[i]=='(') st.push(i);
            if(s[i]==')') {
                if(st.empty()) last = i;
                else{
                    // find a matching pair
                    st.pop();
                    if(st.empty())
                        num = max(num,i-last);
                    else
                        num = max(num,i-st.top());  // 
                }
            }
        }
        return num;
    }
};
   
     ^
//   |  traditional way ============================
class Solution {
public:
    int longestValidParentheses(string s) {
    //  2 swipe
    int num = 0; 
    int depth = 0 ;
    int start =-1;  // notice it should be -1
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')  depth++;
        else{
            --depth;
            if(depth<0){
                start = i;
                depth =0;
            }
            else if(depth ==0){
                num = max(num,i-start);
            }
        }
    }
    
    depth = 0;
    start = s.size();   // same idea as start = -1   here start should be 1 larger than the last index number of s
    for(int i=start-1;i>=0;i--){
        if(s[i]==')')  depth++;
        else{
            --depth;
            if(depth<0){
                start = i;
                depth =0;
            }
            else if(depth ==0){
                num = max(num,start-i);
            }
        }
    }
    return num;
    }
};





