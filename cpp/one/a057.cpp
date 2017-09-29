/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int n = intervals.size();
        
        // Sort by start
        sort(intervals.begin(), intervals.end(), [](const Interval& left, const Interval& right) {
            return left.start < right.start;
        });
        
        vector<Interval> result;
        
        int i = 0;
        while (i < n && intervals[i].end < newInterval.start)
            result.push_back(intervals[i++]);
        
        // Update overlap.
        while (i < n && newInterval.end >= intervals[i].start) 
        {
            if (intervals[i].end > newInterval.end)
                newInterval.end = intervals[i].end;
            if (intervals[i].start < newInterval.start)
                newInterval.start = intervals[i].start;
            i++;
        }
        result.push_back(newInterval);
        
        // Rest
        while (i < n)
            result.push_back(intervals[i++]);
            
        return result;
    }
};