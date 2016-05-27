class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        # Hash table.
        ht = dict();
        for word in words:
            if word not in ht:
                ht[word] = 1
            else:
                ht[word] += 1
        
        # Length of each word.
        wl = len(words[0])
        # Substring indices.
        indices = list()
        for i in xrange(len(s) - len(words) * wl + 1):
            # Copy hash table, which can be modified.
            htt = ht.copy()
            k = i
            total = 0
            while (k-i) < len(words)*wl:
                # Get a word.
                word = s[k:k+wl]
                if word not in htt:
                    break
                if htt[word] == 0:
                    break
                
                htt[word] -= 1
                total += 1  # total words that have been found.
                k += wl     # step
                
                if total == len(words):
                    indices.append(k-len(words)*len(words[0]))
                    break
        return indices

if __name__ == '__main__':
    s = Solution()
    print s.findSubstring("wordgoodgoodgoodbestword", ["word","good","best","good"])
    print s.findSubstring("a", ["a"])