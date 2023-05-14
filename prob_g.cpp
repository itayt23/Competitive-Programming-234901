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

const int MAXN = 1000;

void mul_circulant(ll x[], ll out_mat[], int n, ll m) {
  ll mul_res[MAXN];

  for (int i = 0; i < n; i++) {
    ll sum = 0;
    for (int j = 0; j <= i; j++)
      sum += x[j] * out_mat[i - j];
    for (int j = i + 1; j < n; j++)
      sum += x[j] * out_mat[i - j + n];
    mul_res[i] = sum;
  }

  for (int i = 0; i < n; i++) {
    if (mul_res[i] >= m) mul_res[i] %= m;
    out_mat[i] = mul_res[i];
  }
}

int main() {
  int cases;
  cin >> cases;
  while (cases--) {
    int n, s_times, l, r, x;
    ll m = 1;
    ll enc[MAXN];
    ll circulant_matrix[MAXN];  // circulant matrix
    cin >> n >> s_times >> l >> r >> x;
    for (int i = 0; i < x; i++) m = m * 10;
    for (int i = 0; i < n; i++) {
      cin >> enc[i];
      enc[i] %= m;
    }
    for (auto &element : circulant_matrix) {
      element = 0;
    }
    circulant_matrix[0] = 1, circulant_matrix[1] = l, circulant_matrix[n - 1] = r;
    while (s_times) {
        if (s_times % 2 == 1) mul_circulant(circulant_matrix, enc, n, m);
        mul_circulant(circulant_matrix, circulant_matrix, n, m);
        s_times /= 2;
    }
    for (int i = 0; i < n-1; i++){
      cout << enc[i] << " ";
    } 
    cout << enc[n-1] << endl;
  }
  return 0;
}
