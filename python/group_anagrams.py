"""
Group Anagrams
"""
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        res = list()  # return list
        strdict = dict() # hash table
        for stri in strs:
            astr = ''.join(sorted(stri))
            if astr in strdict:     # track sorted string
                idx = strdict.get(astr)
                res[idx].append(stri)
            else:
                strdict[astr] = len(res)
                res.append([stri])
        for i in xrange(len(res)-1): # lexicographic
            res[i] = sorted(res[i])
        return res