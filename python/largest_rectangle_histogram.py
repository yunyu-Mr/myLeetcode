class Solution(object):
   def largestRectangleArea(self, height):
       """
       :type height: List[int]
       :rtype: int
       """
       stack = list() # push index
       max_rec = 0
       height.append(0) # in order to pop the rest stack
       for i in xrange(len(height)):
           while stack and (height[i] < height[stack[-1]]):
               t = stack.pop()
               if not stack: # stack is empty
                   low = 0
               else:
                   low = stack[-1] + 1
               max_rec = max(max_rec, height[t] * (i - low) )
           stack.append(i)
        #   print stack
       return max_rec

if __name__=='__main__':
    s = Solution()
    print s.largestRectangleArea([1])