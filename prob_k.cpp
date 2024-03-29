#include <algorithm>
#include <bitset> 
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>  
#include <deque>  
#include <functional>
#include <iostream>  
#include <map>  
#include <queue>  
#include <set>  
#include <stack>  
#include <string> 
#include <vector>  
#include <numeric>  

using namespace std;
typedef long long ll;
typedef unsigned long long ull;  
typedef vector<int> vi;  
typedef pair<int, int> pii;

#define inf 1000000000

struct Point {
    double x, y;
};

double cross_product(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);
}

double distance(const Point& p1, const Point& p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double point_to_line_distance(const Point& p, const Point& l1, const Point& l2) {
    return abs(cross_product(l1, l2, p)) / distance(l1, l2);
}

double max_dis_to_line(const vector<Point>& points, const Point& l1, const Point& l2) {
    double max_size = 0.0;
    for (int i = 0; i < points.size(); i++) {
        double dist = point_to_line_distance(points[i], l1, l2);
        if (dist > max_size) {
            max_size = dist;
        }
    }
    return max_size;
}
double find_min_distance(const vector<Point>& points) {
    int sides = points.size();
    int p0 = 0;
    for (int i = 1; i < sides; i++) {
        if (points[i].x < points[p0].x || (points[i].x == points[p0].x && points[i].y < points[p0].y)) {
            p0 = i;
        }
    }

    double min_slot_size = inf;
    int check_sides = sides;
    int cur = p0;
    int next = (cur + 1) % sides;
    double max_size = 0.0;
    while(check_sides--){
        max_size = max_dis_to_line(points, points[cur], points[next]);
        if (max_size < min_slot_size) min_slot_size = max_size;
        cur = next;
        next = (cur + 1) % sides;
    }

    return min_slot_size;
}

int main() {
    int sides;
    cin >> sides;

    vector<Point> points(sides);
    for (int i = 0; i < sides; i++) {
        cin >> points[i].x >> points[i].y;
    }

    double min_slot_size = find_min_distance(points);

    cout << min_slot_size << endl;

    return 0;
}