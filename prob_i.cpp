#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int INF = numeric_limits<int>::max();

void Dijkstra(const vvii& g, int s, vi& dist, vi& ways) {
    dist = vi(g.size(), INF);
    ways = vi(g.size(), 0);
    dist[s] = 0;
    ways[s] = 1;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});

    while (!q.empty()) {
        ii front = q.top();
        q.pop();

        int d = front.first, u = front.second;
        if (d > dist[u]) continue;

        for (ii next : g[u]) {
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
    Dijkstra(adj, start, dist, ways);

    cout << ways[end] << endl;

    return 0;
}