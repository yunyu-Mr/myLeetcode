# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[Interval]
        :type newInterval: Interval
        :rtype: List[Interval]
        """
        result = []
        if len(intervals) == 0:
            result.append(newInterval)
            return result
        i = 0
        inserted = False
        while i < len(intervals):
            # Situation: insert at front
            if newInterval.end < intervals[i].start:
                result.append(newInterval)
                inserted = True
                break
            if newInterval.start <= intervals[i].end:
                newInterval.start = min(newInterval.start, intervals[i].start)

                while i < len(intervals) - 1:
                    if newInterval.end < intervals[i+1].start:
                        newInterval.end = max(newInterval.end, intervals[i].end)
                        result.append(newInterval)
                        inserted = True
                        i += 1
                        break
                    i += 1

                if i == len(intervals)-1 and newInterval.end >= intervals[i].start:
                    newInterval.end = max(newInterval.end, intervals[i].end)
                    result.append(newInterval)
                    inserted = True
                    i += 1
                break
            else:
                result.append(intervals[i])
            i += 1
        # Situation: insert at tail
        if not inserted:
            result.append(newInterval)
        while i < len(intervals):
            result.append(intervals[i])
            i += 1
        return result

if __name__ == '__main__':
    s = Solution()
    intervals = [
        Interval(1,2),
        Interval(3,5),
        Interval(6,7)
    ]
    newInterval = Interval(-1,0)
    res = s.insert(intervals, newInterval)
    for e in res:
        print '%d, %d' %(e.start, e.end)