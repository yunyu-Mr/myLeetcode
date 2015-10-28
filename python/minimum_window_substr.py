class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        # d is a dict() to track the current sub window.
        # dr is a reference dict(), which must be satisfied.
        d, dr = dict(), dict()
        # Init the two dict()
        for e in t:
            d[e] = 0
            if not dr.get(e):
                dr[e] = 1
            else:
                dr[e] += 1
        # print d, dr
        # Two pointers l and h.
        l, h = 0, 0
        # First expand `h` pointer. A minimum substr s[0:h]
        while self.moreDict(d, dr) == 0 and h < len(s):
            if dr.get(s[h]) >= 1:
                d[s[h]] += 1
            h += 1
        # If the whole str s can not include t, return None.
        if self.moreDict(d, dr) == 0:
            return ""
        # track min length and start point
        min_len = len(s)
        min_low = 0
        while True:
            # Shrink from left, to as right as it can.
            while True:
                if d.get(s[l]) and d.get(s[l]) == dr.get(s[l]):
                    break
                if d.get(s[l]) > dr.get(s[l]):
                    d[s[l]] -= 1
                    l += 1
                elif not dr.get(s[l]):
                    l += 1
            # Record minimum length
            if h-l < min_len:
                min_len = h-l
                min_low = l
            # print "l=%d, h=%d" % (l, h)
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
        Check whether d is under the constraint of dr.

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

if __name__ == '__main__':
    s = Solution()
    print s.minWindow('ab', 'b')
    # print s.compareDict({'b':2, 'a':1}, {'a':1, 'b':2})