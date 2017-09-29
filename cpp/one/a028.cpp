class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        
        // 注意，不可直接使用 haystack.length() - needle.length()，
        // 因为这两个是 unsigned int，直接相减会报错，
        // 需要先转为 int。
        int m = haystack.length(), n = needle.length();

        int i;
        for (i = 0; i < m - n + 1; i++) {
            int j = 0;
            for (; j < n; j++)
                if (haystack[i+j] != needle[j])
                    break;
            
            if (j == n) return i;
            
            // i += j + 1;
        }
        return -1;
    }
};