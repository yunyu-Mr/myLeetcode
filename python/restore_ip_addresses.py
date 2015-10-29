class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        self.max_len = 12
        self.addresses = list()
        self.backtracing(s, "", 0)
        return self.addresses

    def backtracing(self, s, address, t):
        print address
        if t > 3:
            self.addresses.append(address[:len(address)-1])
            return
        else:
            sa = "".join(address.split("."))
            for i in xrange(1, min(3, len(s)-len(sa)) + 1):
                if self.constraint(s, sa, t, i):
                    self.backtracing(s, address + s[len(sa):len(sa)+i] + ".", t+1)

    def constraint(self, s, sa, t, i):
        diff = len(s) - len(sa)
        if (diff <= self.max_len - 3*t) and (diff > 0):
            # The first num should not be '0', for example '011'
            if i > 1 and s[len(sa)] == "0":
                return False
            # s shouldn't remain nums
            if t == 3 and diff != i:
                return False
            # Each field shoud less than 256
            if i == 3 and int(s[len(sa):len(sa)+i]) >= 256:
                return False
            # Otherwise, it's ok!
            return True
        return False

if __name__ == '__main__':
    s = Solution()
    print s.restoreIpAddresses("172162541")