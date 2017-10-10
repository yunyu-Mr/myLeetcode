class Solution(object):
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        from collections import deque
        
        n = len(nums)
        if n == 0 or k == 0:
            return []
        
        maxList = []  # Maximum list in sliding windows
        q = deque()   # Store "index" of current maximum.
        
        for i in range(k):  # Init k
            while len(q) > 0 and nums[i] > nums[q[-1]]: # q[0] is the max in windows
                q.pop()
            q.append(i)
        maxList.append(nums[q[0]])
        
        for i in range(k, n):
            # Pop elements smaller than current
            while len(q) > 0 and nums[i] > nums[q[-1]]:
                q.pop()
            q.append(i)
            
            # Pop elements outter current windwos.
            # Ensure q[0] is the max of current window.
            while q[0] <= i-k:
                q.popleft()

            maxList.append(nums[q[0]])
        return maxList