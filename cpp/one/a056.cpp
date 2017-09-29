#include <vector>
#include <iostream>
using namespace std;

//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return intervals;
        
        // Sort by start.
        auto cmp = [](const Interval& left, const Interval& right) {
                return left.start < right.start;
        };
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<Interval> res;
        Interval mInter = intervals[0];
        for (const auto& interval : intervals) {
            if (interval.start <= mInter.end)
                mInter.end = max (mInter.end, interval.end);
            else {
                res.push_back(mInter);
                mInter = interval;
            }
        }
        res.push_back(mInter);
        return res;
    }
};