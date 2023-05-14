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
#include <iomanip>
#include <climits>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;  
typedef vector<int> vi;  
typedef pair<int, int> pii;

double max_min_func(vector<pair<int, int>> &A, double t) {
  double min_pos = INT_MAX;
  double max_pos = INT_MIN;
  for (int i = 0; i < A.size(); i++) {
    double pos = A[i].first + A[i].second * t;
    min_pos = min(min_pos, pos);
    max_pos = max(max_pos, pos);
  }
  return max_pos - min_pos;
}

double ternary_search(vector<pair<int, int>> &A) {
  double left = 0, right = 1e9;
  for (int i = 0; i < 100; i++) {
    double mid1 = left + (right - left) / 3;
    double mid2 = right - (right - left) / 3;
    if (max_min_func(A, mid1) < max_min_func(A, mid2)) {
      right = mid2;
    } else {
      left = mid1;
    }
  }
  return max_min_func(A, left);
}

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> A;
  for (int i = 0; i < n; i++) {
    int x, v;
    cin >> x >> v;
    A.push_back(make_pair(x, v));
  }
  double result = ternary_search(A);

  cout << result;
}
