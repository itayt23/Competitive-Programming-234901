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

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<pair<double, double>> vertices;
    for (int i = 0; i < num; i++) {
        double x, y;
        cin >> x >> y;
        vertices.push_back(make_pair(x, y));
    }
    vector<double> answer;
    for (int i = 0; i < num; i++) {
        vector<double> dists;
        double x1 = vertices[i].first;
        double y1 = vertices[i].second;
        double x2 = vertices[(i + 1) % num].first;
        double y2 = vertices[(i + 1) % num].second;
        for (int j = 0; j < num; j++) {
            double x0 = vertices[j].first;
            double y0 = vertices[j].second;
            double top = abs((y2 - y1) * x0 - (x2 - x1) * y0 + x2 * y1 - y2 * x1);
            double bot = sqrt(pow(y2 - y1, 2) + pow(x2 - x1, 2));
            double d = top / bot;
            dists.push_back(d);
        }
        answer.push_back(*max_element(dists.begin(), dists.end()));
    }
    cout << *min_element(answer.begin(), answer.end()) << endl;
    return 0;
}
