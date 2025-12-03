#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;
    // adjacency matrix for rail graph
    vector<vector<char>> rail(n+1, vector<char>(n+1, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        rail[u][v] = rail[v][u] = 1;
    }
    // check whether there's a rail between 1 and n
    bool rail1n = rail[1][n];
    // we choose which graph to BFS on:
    // if rail1n -> BFS on roads (complement), else BFS on rails.
    vector<int> dist(n+1, -1);
    deque<int> q;
    dist[1] = 0;
    q.push_back(1);

    while (!q.empty()) {
        int v = q.front(); q.pop_front();
        for (int to = 1; to <= n; ++to) {
            if (to == v) continue;
            // decide whether edge v--to exists in chosen graph
            bool edge;
            if (rail1n) {
                // use roads => edge exists if there is NO rail
                edge = !rail[v][to];
            } else {
                // use rails => edge exists if there IS rail
                edge = rail[v][to];
            }
            if (!edge) continue;
            if (dist[to] == -1) {
                dist[to] = dist[v] + 1;
                q.push_back(to);
            }
        }
    }

    cout << dist[n] << "\n"; // -1 if unreachable (dist[n] == -1)
    return 0;
}