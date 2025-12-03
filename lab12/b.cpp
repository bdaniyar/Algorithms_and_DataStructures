#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;

vector<vector<pair<int,int>>> g;

vector<ll> dijkstra(int start, int n) {
    vector<ll> dist(n+1, INF);
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<pair<ll,int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [d, v] = pq.top(); pq.pop();
        if (d != dist[v]) continue;

        for (auto &edge : g[v]) {
            int to = edge.first;
            int w  = edge.second;
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    g.assign(N+1, {});

    for (int i = 0; i < M; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        g[v].push_back({u, c});
        g[u].push_back({v, c});
    }

    int s, a, b, f;
    cin >> s >> a >> b >> f;

    vector<ll> distS = dijkstra(s, N);
    vector<ll> distA = dijkstra(a, N);
    vector<ll> distB = dijkstra(b, N);

    ll ans = INF;

    // s → a → b → f
    if (distS[a] < INF && distA[b] < INF && distB[f] < INF)
        ans = min(ans, distS[a] + distA[b] + distB[f]);

    // s → b → a → f
    if (distS[b] < INF && distB[a] < INF && distA[f] < INF)
        ans = min(ans, distS[b] + distB[a] + distA[f]);

    if (ans == INF) cout << -1;
    else cout << ans;

    return 0;
}