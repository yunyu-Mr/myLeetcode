class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // vector<int> tmp;
        // int i = 0, j = 0;
        // while (i < m && j < n)
        //     if (nums1[i] < nums2[j]) tmp.push_back(nums1[i++]);
        //     else                     tmp.push_back(nums2[j++]);
        // for (; i < m; i++)  tmp.push_back(nums1[i]);
        // for (; j < n; j++)  tmp.push_back(nums2[j]);
        // for (int k = 0; k < m + n; k++)
        //     nums1[k] = tmp[k];
        
        int i = m-1, j = n-1, k = m+n-1;
        while (i >=0 && j >= 0) {
            if (nums1[i] > nums2[j]) nums1[k] = nums1[i--];
            else                     nums1[k] = nums2[j--];
            k--;
        }
        for (; i >= 0; i--) nums1[k--] = nums1[i];
        for (; j >= 0; j--) nums1[k--] = nums2[j];
    }
};