class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        print nums
        
        foursum = list()
        for i in xrange(len(nums)-4+1):
            l, r = i + 1, len(nums) - 1
            # k = l + 1
            while r - l > 1:
                print i, l, r
                s = nums[l] + nums[r]
                for k in xrange(l+1, r-1):
                    # print s + nums[i] + nums[k]
                    print k
                    if nums[i] + nums[k] + s == target:
                        foursum.append([nums[i], nums[k], nums[l], nums[r]])
                        print foursum
                
                l, r = l+1, r-1
                while l < r:
                    if nums[l] != nums[l-1]:
                        break
                    l += 1
                while r > l:
                    if nums[r] != nums[r+1]:
                        break
                    r -= 1
                    
                # print i, l, k, r
        return foursum

if __name__ == '__main__':
    s = Solution()
    print s.fourSum([1, 0, -1, 0, 2, -2], 0)