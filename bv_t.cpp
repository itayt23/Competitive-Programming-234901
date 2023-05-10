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

int* values;
int n;
double ratio;

struct Veg {
    int k;
    double curMin;
    double curMax;
    int curCuts;

    Veg(int k, double curMin, double curMax, int curCuts) :
        k(k), curMin(curMin), curMax(curMax), curCuts(curCuts) {}

    bool operator>(const Veg& other) const {
        return curCuts > other.curCuts;
    }
};

int cutting() {
    priority_queue<Veg, vector<Veg>, greater<Veg>> min_heap;
    min_heap.push(Veg(0, values[0], values[0], 0));

    while (!min_heap.empty()) {
        Veg veg = min_heap.top();
        min_heap.pop();

        if (veg.k == n) {
            return veg.curCuts;
        }

        double upper_bound = veg.curMin / ratio;
        double lwer_bound = veg.curMax * ratio;
        int low = ceil(values[veg.k] / upper_bound);
        int high = floor(values[veg.k] / lwer_bound);

        if (veg.k == 0) {
            low = 1;
            high = values[0];
        }

        for (int i = low; i <= high; i++) {
            double newL = values[veg.k] / i;

            double curMin = veg.curMin;
            double curMax = veg.curMax;

            if (veg.k == 0) {
                curMin = newL;
                curMax = newL;
            } else {
                curMin = min(curMin, newL);
                curMax = max(curMax, newL);
            }

            min_heap.push(Veg(veg.k + 1, curMin, curMax, veg.curCuts + i - 1));
        }
    }
    return 0;
}

int main() {
    int min_cuts;
    cin >> ratio >> n;

    values = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    sort(values, values + n);
    min_cuts = cutting();
    cout << min_cuts << endl;

    return 0;
}


