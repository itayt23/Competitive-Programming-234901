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

int solve(int k, double curMin, double curMax, int curCuts) {
    if (k == n) {
        return curCuts;
    }

    double absMax = curMin / ratio;
    double absMin = curMax * ratio;
    int low = ceil(values[k] / absMax);
    int high = floor(values[k] / absMin);

    if (k == 0) {
        low = 1;
        high = values[0];
    }

    for (int i = low; i <= high; i++) {
        double newL = values[k] / i;

        if (k == 0) {
            curMin = newL;
            curMax = newL;
        }

        int ans = solve(k + 1, min(curMin, newL), max(curMax, newL), curCuts + i - 1);
        if (ans != -1) {
            return ans;
        }
    }
    return -1;
}

int main() {
    int min_cuts;
    cin >> ratio >> n;

    values = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }

    sort(values, values + n);
    min_cuts = solve(0, values[0], values[0], 0);
    cout << min_cuts << endl;

    return 0;
}

