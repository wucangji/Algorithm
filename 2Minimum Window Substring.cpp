class Solution {
public:
    string minWindow(string S, string T) {
        //双指针
        if(S.empty()) return "";
        if(S.size()<T.size()) return "";
        
        int ASCMAX=256;
        int appeared_count[ASCMAX];
        int expected_count[ASCMAX];
        fill(appeared_count,appeared_count+ASCMAX,0);  //  这两行不能少，说明默认数组不是0？
        fill(expected_count,expected_count+ASCMAX,0);
        
        for(int i=0;i<T.size();i++) expected_count[T[i]] ++;      // 要出现的地方为1
        
        int minWidth = INT_MAX, min_start = 0;
        int wnd_start = 0;
        int appeared = 0;
        // 尾指针不断往后
        for(int wnd_end=0;wnd_end<S.size();wnd_end++){
            if(expected_count[S[wnd_end]]>0){  // contain expected element, can be more than 1
                appeared_count[S[wnd_end]]++;
                if(appeared_count[S[wnd_end]] <= expected_count[S[wnd_end]]) appeared++;    // appear的多了 也没用
            }
            
            if(appeared == T.size()){ // mission complete now 收缩头指针
                while(appeared_count[S[wnd_start]] > expected_count[S[wnd_start]] 
                       || expected_count[S[wnd_start]] == 0)  {//多了或者原来不需要
                       appeared_count[S[wnd_start]]--; // might be -1, but doesn't matter
                       wnd_start++;
                }
                if (minWidth>(wnd_end-wnd_start+1)){
                    minWidth = wnd_end-wnd_start+1;
                    min_start = wnd_start;
                }
            }
        }
        if(minWidth == INT_MAX) return "";
        else return S.substr(min_start,minWidth);   // wnd _start 有很多个  min_start 才是最小的
        
    }
};