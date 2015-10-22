# Definition for an interval.
class Interval(object):
    def __init__(self, s=0, e=0):
        self.start = s
        self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        if len(intervals) < 1:
            return intervals

        # sort by .end
        intervals.sort(key=lambda interval:interval.end)

        res = list()
        i = len(intervals) - 1
        while i > 0:
            if intervals[i].start <= intervals[i-1].end:
                intervals[i-1].end = intervals[i].end
                if intervals[i-1].start > intervals[i].start:
                    intervals[i-1].start = intervals[i].start
            else:
                res.append(intervals[i])
            i -= 1
        # add the first skipping one
        res.append(intervals[0])
        return res[::-1] # reverse

if __name__ == '__main__':
    a = list()
    # for i in xrange(1,4):
    #     a.append(Interval(i, i+3))

    a.append(Interval(5, 6))
    a.append(Interval(4, 7))
    a.append(Interval(1, 2))
    s = Solution()
    s.merge(a)