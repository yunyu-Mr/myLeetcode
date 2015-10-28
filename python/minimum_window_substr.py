class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        d, dr = dict(), dict()
        for e in t:
            d[e] = 0
            if not dr.get(e):
                dr[e] = 1
            else:
                dr[e] += 1

        l, h = 0, 0
        while min(d.values()) < 1 and h < len(s):
            if d.get(s[h]) >= 0:
                d[s[h]] += 1
            h += 1
        if min(d.values()) == 0:
            return ""
        min_len = len(s)
        min_low = 0
        while True:
            # Shrink from left
            while True:
                if d.get(s[l]) == 1:
                    break
                if d.get(s[l]) > 1:
                    d[s[l]] -= 1
                    l += 1
                elif not d.get(s[l]):
                    l += 1
            if h-l < min_len:
                min_len = h-l
                min_low = l
            print "l=%d, h=%d" % (l, h)
            # Expand right
            if h < len(s):
                if d.get(s[h]) >= 1:
                    d[s[h]] += 1
                h += 1
            else:
                break
        return s[min_low: min_low + min_len]

    def moreDict(self, d, dr):
        """
        :param d: dict
        :param dr: dict
        :return: int
        """
        for (k,v), (kr, vr) in zip(d.items(), dr.items()):
            if k != kr:
                return -1
            if v < vr:
                return 0
        return 1

    def lessDict(self, d, dr):
        """
        :param d: dict
        :param dr: dict
        :return: int
        """
        for (k,v), (kr, vr) in zip(d.items(), dr.items()):
            if k != kr:
                return -1
            if v == vr:
                return 0
        return 1

if __name__ == '__main__':
    s = Solution()
    # print s.minWindow('ABDEBANCFABCD', 'ABC')
    # print s.compareDict({'b':2, 'a':1}, {'a':1, 'b':2})