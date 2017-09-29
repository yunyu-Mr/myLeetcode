#include <stdio.h>
#include <iostream>
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

// Definition for a line.
struct Line {
    // y = kx + b;
    double slope;   // k
    double b;       // b
    Line (double s, double b):slope(s),b(b){};
};

// Custom equal operator.
bool operator==(const Line& lhs, const Line& rhs) {
        return lhs.slope == rhs.slope && lhs.b == rhs.b;
}

// Custom hash function.
namespace std{
    template <> 
    struct hash<Line>
    {
        size_t operator()(Line const& line) const {
            using std::hash;
            using std::size_t;

            size_t hashc = 17;
            hashc = hashc * 31 + hash<double>() (line.slope);
            hashc = hashc * 31 + hash<double>() (line.b);
            return hashc;
        }
    };
}


class Solution {
// typedef map<pair<double, double>, int> LineMap;
typedef unordered_map<Line, int>       LineMap;
typedef unordered_map<int, int>        Vertical;
// typedef pair<double, double>           LineSig;

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
                    Line line = calLine (a, b);  // calculate line signature.
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
    
    Line calLine(const Point &a, const Point &b) {
        // y = kx + C
        double slope = (double) (a.y - b.y) / (a.x - b.x);
        double C = a.y - slope * a.x;
        printf("%f, %f\n", slope, C);
        Line line(slope, C);
        return line;
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