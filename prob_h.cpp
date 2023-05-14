#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
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
typedef vector<vi> vvi;

#define inf 1000000000

int get_index(vector<string>& names, string& name) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            return i;
        }
    }
    names.push_back(name);
    return names.size() - 1;
}

void floyd(vvi& adj_mat, int numVertices) {
    for (int k = 0; k < numVertices; k++) {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
            }
        }
    }
}

int main() {
    int n, r, tc = 1;
    while (cin >> n >> r && (n || r)) {
        vector<string> names;
        vvi adj_mat(n, vi(n, inf));
        for (int i = 0; i < r; i++) {
            string a, b;
            cin >> a >> b;
            int aa = get_index(names, a), bb = get_index(names, b);
            adj_mat[aa][bb] = adj_mat[bb][aa] = 1;
        }
        floyd(adj_mat, n);
        bool poss = true;
        int mx = -inf;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (adj_mat[i][j] == inf) {
                    poss = false;
                    break;
                }
                mx = max(mx, adj_mat[i][j]);
            }
            if (!poss) break;
        }
        cout << "Network " << tc++ << ": ";
        if (poss) {
            cout << mx << endl;
        } else {
            cout << "DISCONNECTED\n";
        }
        cout << endl;
    }
    return 0;
}
