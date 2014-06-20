class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        if(!*needle) return haystack;  // return the first occurance;  do not forget the * 
        char* p1_ahead = haystack;
        for(char *p2 =needle;*p2;p2++){   // not p2  exists, is *p2 exists.
            p1_ahead++;
        }
        p1_ahead--;// back 1 space
        for(char *p1 = haystack;*p1_ahead;p1_ahead++){
        
            char *old_p1 = p1;
            char *p2 = needle;
            while(*p1 && *p2 && *p1 == *p2){
                p1++;
                p2++;
            }
            if(!*p2) return old_p1;  // not return *old_p1, return the pointer
            p1 = old_p1+1;
        }
        return NULL;
    }
};