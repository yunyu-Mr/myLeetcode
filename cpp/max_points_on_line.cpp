#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;

//Definition for a point.
struct Point {
     int x;
     int y;
     Point() : x(0), y(0) {}
     Point(int a, int b) : x(a), y(b) {}
};

class Solution {
typedef map<pair<double, double>, int> LineMap;
typedef unordered_map<int, int>        Vertical;
typedef pair<double, double>           LineSig;

public:
    int maxPoints(vector<Point>& points) {
        int N = points.size();
        if (N < 3) return N;
        
        int maxNum = 0;
        
        for (int i = 0; i < N-1; i++) 
        {
            int samePoints = 1, // count same points (including itself).
                currMax    = 0; // Max number of points including current point.
            Vertical vertical;
            LineMap lineMap;    // Hash map.
            
            for (int j = i + 1; j < N; j++) 
            {
                Point &a = points[i];
                Point &b = points[j];
                printf("(%d,%d), (%d,%d) ", a.x, a.y, b.x, b.y);

                if      (a.x == b.x && a.y == b.y) samePoints++;
                else if (a.x == b.x) {
                    // Vertical line.
                    if (vertical.find(a.x) == vertical.end()) {
                        vertical[a.x] = 1;
                        currMax = max(currMax, 1);
                        printf("new line\n");
                    }
                    else {
                        currMax = max (currMax, ++vertical[a.x]);
                        printf("add point\n");
                    }
                }
                else {  // Common line.
                    LineSig line = calLine (a, b);  // calculate line signature.
                    if (lineMap.find (line) == lineMap.end()) {
                        lineMap[line] = 1;  // New line.
                        currMax = max(currMax, 1);
                        printf("new line\n");
                    } else {
                        // Add point to existing line.
                        currMax = max(currMax, ++lineMap[line]);
                        printf("add point\n");
                    }
                }
            }
            cout << "same points: " << samePoints << endl;
            maxNum = max(maxNum, currMax + samePoints);
        }
        return maxNum;
    }
    
    LineSig calLine(const Point &a, const Point &b) {
        // y = kx + C
        double slope = (double) (a.y - b.y) / (a.x - b.x);
        double C = a.y - slope * a.x;
        printf("%f, %f\n", slope, C);
        return make_pair(slope, C);
    }
};

int main() {
    Solution s;
    vector<Point> points = {Point(0,0), Point(1,1),Point(1,-1)};
    vector<Point> points2 = {Point(1,1), Point(1,1),Point(1,1)};
    cout << s.maxPoints(points) << endl;
    cout << s.maxPoints(points2) << endl;
    return 0;
}