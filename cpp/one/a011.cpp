class Solution {
public:
    int maxArea(vector<int>& height) {
        int r = height.size() - 1, l = 0;  // two pointers.
        int nr = r, nl = l;                // next larger height.
        int m = (r - l) * min(height[r], height[l]);    // min area.
        
        while (r > l + 1)  // Ensure at least 4 element.
        {
            if (nr == r)
                for (nr = r - 1; nr > l && height[nr] <= height[r]; nr--); // Find next height larger than previous
            if (nl == l)
                for (nl = l + 1; nl < r && height[nl] <= height[l]; nl++);

            int leftArea = (nr - l) * min(height[nr], height[l]);
            int rightArea = (r - nl) * min(height[r], height[nl]);
            
            // Compare 2 areas, then shrink r and l.
            if (leftArea > rightArea) {
                r = nr;
                m = max(m, leftArea);
            }else {
                l = nl;
                m = max(m, rightArea);
            }
        }
        // Edge: 3 elements. Two part, left and right.
        if (r == l+1) 
            m = max(m, max(min(height[r], height[r-1]), 
                           min(height[l], height[l+1])));
        
        return m;
    }
};