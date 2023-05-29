#include <iostream>
#include <vector>
#include <queue>
#include <limits>
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

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<vii> vvii;

#define inf 1000000000

void dijkstra(const vvii& g, int s, vi& dist, vi& ways) {
    dist = vi(g.size(), inf);
    ways = vi(g.size(), 0);
    dist[s] = 0;
    ways[s] = 1;
    priority_queue<pii, vii, greater<pii>> q;
    q.push({0, s});

    while (!q.empty()) {
        pii front = q.top();
        q.pop();

        int d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (pii next : g[u]) {
            int v = next.first, w = next.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                q.push({dist[v], v});
            } else if (dist[u] + w == dist[v]) {
                ways[v] += ways[u];
            }
        }
    }
}

int main() {
    int vertex, edge;
    cin >> vertex >> edge;

    vvii adj(vertex);

    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }

    int start, end;
    cin >> start >> end;

    vi dist, ways;
    dijkstra(adj, start, dist, ways);

    cout << ways[end] << endl;

    return 0;
}