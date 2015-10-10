class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        stack = list()
        for item in path.split('/'):
            if item not in ['', '.', '..']:
                stack.append(item)
            if item == '..' and stack:
                stack.pop()
        return '/' + '/'.join(stack)

if __name__=='__main__':
    s = Solution()
    res = s.simplifyPath('/a/b/.././c/')
    print 'result = %s' % res