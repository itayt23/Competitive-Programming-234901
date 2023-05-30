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
#define PI 3.14159265358979323846
#define EPS 1e-2

 
struct Point {
    double x,y;
    Point(){}
    Point(double x,double y):x(x),y(y){}
    Point operator + (const Point &p) const {return Point(x+p.x,y+p.y);}
    Point operator - (const Point &p) const {return Point(x-p.x,y-p.y);}
    Point operator * (double c) const { return Point(x*c, y *c);}
    Point operator / (double c) const { return Point(x/c, y /c);}
    double norm(){return sqrt(x*x+y*y);}
};

struct Instruction {
    string cmd;
    int arg;
    int size;
};

Point rotate_counter_clock(Point p,double ang)
{
    return Point(p.x*cos(ang) - p.y*sin(ang) , p.x*sin(ang) + p.y * cos(ang));
}

Point apply_instructions(Instruction* instruction,Point& previous_direction,int exclude_index= -1)
{
    Point pivot = Point(0,0);
    Point direction = Point(1,0);
    for(int i = 0; i < instruction->size ; i ++ ) {
        if(i==exclude_index) {
            previous_direction= direction;
            continue;
        }
        string cmd = instruction[i].cmd;
        double size = instruction[i].arg;
        if(cmd.compare("fd")== 0) pivot = pivot + direction * size;
        if(cmd.compare("bk")== 0) pivot = pivot - direction * size;
        if(cmd.compare("lt")== 0) {
            size = PI * size / 180;
            direction = rotate_counter_clock(direction,size);
        } 
        if(cmd.compare("rt")== 0){
            size = PI * size / 180;
            direction = rotate_counter_clock(direction,-size);
        } 
    }
    return pivot;
}
 
 
int main()
{
    int commands;
    Point previous_direction;
    int test_cases, find_index;
    cin >> test_cases;
    while(test_cases--) {
        cin >> commands;
        find_index = 0;
        Instruction instructions[1000];
        instructions->size = commands;
        for (int i = 0; i < commands; i++){
            string arg;
            cin >> instructions[i].cmd >> arg;
            if(arg.compare("?") == 0) {
                find_index = i;
                instructions[i].arg = 0;
            }
            else{instructions[i].arg =  atoi(arg.c_str());}
        }
        if(instructions[find_index].cmd.compare("fd") == 0 || instructions[find_index].cmd.compare("bk") == 0) {
            Point final_position = apply_instructions(instructions,previous_direction,find_index);
            int direction_sign  = (instructions[find_index].cmd.compare("fd") == 0 ? -1 : 1);
            cout << fixed << static_cast<int>(final_position.x / previous_direction.x * direction_sign  + EPS) << endl;
        }
        else {
            for(int ang = 0; ang < 360; ang ++ ) {
                instructions[find_index].arg = ang;
                Point res_pos = apply_instructions(instructions, previous_direction);
                if(fabs(res_pos.norm()) < EPS) {
                    cout << ang << endl;
                    break;
                }
            }
        }
         
    }
}