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

int get_index_of_name(vector<string>& names, string& name) {
    for (int i = 0; i < names.size(); i++) {
        if (names[i] == name) {
            return i;
        }
    }
    names.push_back(name);
    return names.size() - 1;
}


void floyd(vvi& adj_mat, int v) {
    for (int k = 0; k < v; k++) {
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                adj_mat[i][j] = min(adj_mat[i][j], adj_mat[i][k] + adj_mat[k][j]);
            }
        }
    }
}

int main() {
    int p, r, network_num = 1;
    cin >> p >> r;
    while (p || r) {
        vector<string> names;
        vvi adj_mat(p, vi(p, inf));
        for (int i = 0; i < r; i++) {
            string name_1, name_2;
            cin >> name_1 >> name_2;
            int name_1_index = get_index_of_name(names, name_1);
            int name_2_index = get_index_of_name(names, name_2);
            adj_mat[name_1_index][name_2_index] = adj_mat[name_2_index][name_1_index] = 1;
        }
        floyd(adj_mat, p);
        bool disconnected = false;
        int max_degree = -inf;
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < p; j++) {
                if (i == j) continue;
                if (adj_mat[i][j] == inf) {
                    disconnected = true;
                    break;
                }
                max_degree = max(max_degree, adj_mat[i][j]);
            }
            if (disconnected) break;
        }
        cout << "Network " << network_num++ << ": ";
        if (disconnected) {
            cout << "DISCONNECTED\n";
        } else {
            cout << max_degree << endl;
        }
        cout << endl;
        cin >> p >> r;
    }
    return 0;
}
