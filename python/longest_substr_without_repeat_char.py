class Solution:
    # @return an integer
    def lengthOfLongestSubstring(self, s):
        #without repeat char
        
        max_len = 0     # record max length
        curr_len = 0    # record current length
        charmap = dict() # hash map
        
        for i in xrange(len(s)):
            ch = s[i]
            curr_len += 1
            
            # if repeat, refresh current char
            if charmap.get(ch) !=None: 
                curr_len = min(curr_len, i-charmap.get(ch))

            charmap[ch] = i # hash map add none-repeat char
                
            max_len = max(curr_len, max_len)
        
        return max_len
