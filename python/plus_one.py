'''
Plus One
'''
class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        carry = 1
        for i in xrange(len(digits)-1, -1, -1):
            if carry + digits[i] == 10:
                digits[i] = 0
                carry = 1
            else:
                digits[i] += carry
                carry = 0
        if carry > 0:
            return [1] + digits
        return digits