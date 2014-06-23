/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int countRepeat(int i, vector<Point> &p){   // find the repeat element of i th
        int c=1;
        for(int j=i+1;j<p.size();j++){
            if(p[j].x==p[i].x && p[j].y==p[i].y)  c++;
        }
        return c;
    }
    
    int maxPoints(vector<Point> &points) {
        if(points.size()<3) return points.size();
        int repeat = countRepeat(0,points); 
        if(repeat == points.size()) return repeat;  //  有可能有点重合，这样的话算斜率是算不出来的
        
        
        unordered_map<double,int> mdi;      //  斜率对应的点数表
        unordered_map<double, int> marks;   //  斜率表
        int mp = 2;
        
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                if(points[i].x == points[j].x  && points[i].y == points[j].y) continue;
                double a = points[i].x - points[j].x;
                double b = points[i].y - points[j].y;
                double k = a? b/a:(double)INT_MAX;   //   斜率最大可以单独 考虑么？
                if(!marks.count(k)){    //若该斜率不存在
                    marks[k] = i+1;     //  新建这个斜率 mark 表
                    mdi[k] = repeat+1;
                }
                else if(marks[k] == i+1)  mdi[k]++;   // 该斜率已经存在的话  只能计算当时的这一波点，下一波的话会重复算点的。
            }
            for(auto it: mdi) mp = max(mp,it.second);
            repeat = countRepeat(i+1,points);
            mdi.clear();
        }
        return mp;
    }
};