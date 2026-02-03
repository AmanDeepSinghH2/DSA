#include <iostream>

using namespace std;

struct Point {
    int x, y;
};

// 0 -> p, q and r are collinear
// 1 -> Clockwise
// 2 -> Counterclockwise
int orientation(Point p, Point q, Point r) {
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // collinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

int main() {
    Point p1 = {0, 0}, p2 = {4, 4}, p3 = {1, 2};
    int o = orientation(p1, p2, p3);
    
    cout << "Points: (" << p1.x << "," << p1.y << "), (" 
         << p2.x << "," << p2.y << "), (" 
         << p3.x << "," << p3.y << ")" << endl;

    if (o == 0) cout << "Linear";
    else if (o == 1) cout << "Clockwise";
    else cout << "CounterClockwise";
    cout << endl;

    return 0;
}
