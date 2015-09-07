class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        #without repeat char
        
        max_len = 0
        curr_len = 0
        charmap = dict()
        
        for i in xrange(len(s)):
            ch = s[i]
            curr_len += 1
            
            # repeat
            if charmap.get(ch) !=None: 
                curr_len = min(curr_len, i-charmap.get(ch))

            charmap[ch] = i
                
            max_len = max(curr_len, max_len)
        
        return max_len
