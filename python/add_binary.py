"""
Add Binary
"""
class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        if len(a) > len(b):
            max_len = len(a)
            min_len = len(b)
            longstr = a
            shortstr = b
        else:
            max_len = len(b)
            min_len = len(a)
            longstr = b
            shortstr = a
        res = ''
        carry = 0
        ia, ib = 0, 0
        i, i2 = min_len -1 , max_len -1
        while i >= 0:
            ia, ib = int(shortstr[i]), int(longstr[i2])
            res += str( ia ^ ib ^ carry)            # xor
            carry = (ia&ib)|(ia&carry)|(ib&carry)   # calculate carry
            i-=1
            i2-=1
        while i2 >= 0:
            ia = int(longstr[i2])
            res += str( ia ^ carry)
            carry = carry & ia
            i2-=1
        if carry > 0:
            res += str(carry)
        return res[::-1]