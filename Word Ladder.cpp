class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if(start == end)  return 1;
        int n = start.size();
        if(n<1 || n!=end.size()) return 0;
        
        queue<string> qs1;
        qs1.push(start);
        dict.erase(start); //  set 直接  可以直接  erase
        queue<string> qs2;
        int minLen = 2 ;
        
        while(!qs1.empty()){
            while(!qs1.empty()){
                string s = qs1.front();
                qs1.pop();
                for(int i=0;i<n;i++){
                    char oriChar = s[i];
                    for(char a ='a';a<='z';a++){
                        if(a == oriChar) continue;
                        s[i] = a;
                        if(s == end) return minLen;  // finish job
                        if(dict.count(s)){
                            qs2.push(s);
                            dict.erase(s);
                        }
                    }
                    s[i] = oriChar;   // when finish this letter try[],recover so next letter can try
                }
            }
            // when qs1 = empty this try ends, now try next queue and minlen++
            qs1.swap(qs2);    // if we use qs1 = qs2 , time exceeds.
            minLen++;
        }
        
        return 0;
    }
};