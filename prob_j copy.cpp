#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;

const double PI = acos(-1.0);

struct Point {
    double x, y;
    
    Point(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    
    void moveForward(double distance, double angle) {
        x += distance * cos(angle);
        y += distance * sin(angle);
    }
    
    void rotate(double angle) {
        angle = angle * PI / 180.0;
        double newX = x * cos(angle) - y * sin(angle);
        double newY = x * sin(angle) + y * cos(angle);
        x = newX;
        y = newY;
    }
    
    double distanceFromOrigin() {
        return hypot(x, y);
    }
};

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        char c[1001], buf[100];
        int d[1001], ans;
        int q = -1;
        Point p;
        
        for (int i = 0; i < n; ++i) {
            cin >> c[i] >> buf;
            
            if (buf[0] == '?') {
                q = i;
            } else {
                stringstream ss(buf);
                ss >> d[i];
            }
        }
        
        if (c[q] == 'f' || c[q] == 'b') {
            d[q] = 0;
            Point temp = p;
            temp.moveForward(d[q], p.y);
            double d1 = temp.distanceFromOrigin();
            
            temp = p;
            temp.moveForward(-d[q], p.y);
            double d2 = temp.distanceFromOrigin();
            
            if (d1 > d2) {
                d[q] = -d[q];
            }
        } else {
            for (ans = 0; ans < 360; ++ans) {
                d[q] = ans;
                Point temp = p;
                temp.rotate(d[q]);
                
                if (abs(temp.x) < 0.01 && abs(temp.y) < 0.01) {
                    break;
                }
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}
