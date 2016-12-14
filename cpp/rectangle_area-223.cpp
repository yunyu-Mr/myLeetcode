#include <iostream>

class Solution {
public:
    int computeWidth(int A, int C, int E, int G) {
        // Inside: A|E|G|C or E|A|C|G
        if ((A <= E && C >= G) || (A >= E && C <= G))
            return std::min (C-A, G-E);
        // Overlap: E|A|G|C or A|E|C|G
        if (A > E && A < G) return G - A;
        if (E > A && E < C) return C - E;
        
        return 0;
    }

    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int overlapArea = computeWidth(A, C, E, G) * computeWidth(B, D, F, H);
        int sumArea = (C - A) * (D - B) + (G - E) * (H - F);
        return sumArea - overlapArea;
    }
};