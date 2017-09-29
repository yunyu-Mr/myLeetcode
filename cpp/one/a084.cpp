class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> index;
        
        index.push(0);
        heights.push_back(0);  // in order to pop all in the stack.
        
        for (int i = 1; i < heights.size(); i++) 
        {
            if (heights[i] <= heights[index.top()]) 
            {
                int right = i;  // right bound
                while (!index.empty() && heights[i] <= heights[index.top()]) {
                    int x = index.top();    // lowerst in the current area.
                    index.pop();
                    
                    int left = index.empty() ? -1 : index.top();  // left bound
                    
                    int area = heights[x] * (right - left -1);    // height * width
                    maxArea = max (maxArea, area);
                }
            }
            // highest in the stack
            index.push(i);
        }
        return maxArea;
    }
};