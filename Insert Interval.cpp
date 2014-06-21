/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

// This method run out of time
class Solution {
public:
    vector<Interval> insert(vector<Interval> &v, Interval nv) {
        
vector<Interval> rs;  
        int i = 0;  
        for ( ; i < v.size() && v[i].end < nv.start; i++)  
        {  
            rs.push_back(v[i]);  
        }  
        if (i == v.size())  
        {  
            rs.push_back(nv);  
            return rs;  
        }  
        nv.start = min(nv.start, v[i].start);  
  
        for ( ; i < v.size() && v[i].start <= nv.end; i++)  
        {  
            nv.end = max(nv.end, v[i].end);  
        }  
        rs.push_back(nv);  
  
        for ( ; i < v.size(); i++)  
        {  
            rs.push_back(v[i]);  
        }  
        return rs; 
        
    }
};