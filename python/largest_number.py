"""
Largest Number
"""
def str_cmp(x, y):
	"""
	:type x: str
	:type y: str
	:rtype: int
	"""
	if x + y > y + x:
		return -1  # x > y
	return 1	   # x < y

class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        numstr = [str(n) for n in nums]
        # Default is increasing
        numstr.sort(str_cmp)
        if len(numstr) > 0 and numstr[0] == '0':
        	return '0'
        return ''.join(numstr)

if __name__ == '__main__':
	s = Solution()
	print s.largestNumber([5,9,33,34])