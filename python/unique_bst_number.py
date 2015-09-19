class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        
        u_list = [1,1]
        # Increase from
        # 1
        # 1 2
        # 1 2 3
        # 1 2 3 4
        # 1 2 3 4 5 
        # ...
        for i in xrange(2, n+1): 
            # For example, n = 5, calculate T(5)
            # T(5) = 2*T(0)*T(4) + 2*T(1)*T(3) + T(2)*T(2)
            # T(2n) = 2*T(0)*T(2n-1) + 2*T(1)*T(2n-2) + ... + 2*T(n)*T(n)
            # T(2n+1) = 2*T(0)*T(2n) + 2*T(1)*T(2n-1) + ... + 2*T(n)*T(n) + T(n+1)*T(n+1)
            u_sum = 0
            for j in xrange(1, i/2+1):
                left = j-1
                right = i-j
                u_sum += 2 * u_list[left] * u_list[right]
            if i%2 == 1:
                u_sum += u_list[i/2] * u_list[i/2]
            u_list.append(u_sum)
        return u_list[-1]

if __name__ == '__main__':
    s = Solution()
    print s.numTrees(4)