#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> w(N+1, vector<int>(N+1));
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> w[i][j];

    vector<int> dist(N+1, 0), parent(N+1, -1);
    int x = -1;

    for (int it = 0; it < N; it++) {
        x = -1;
        for (int u = 1; u <= N; u++) {
            for (int v = 1; v <= N; v++) {
                if (w[u][v] < 100000 && dist[v] > dist[u] + w[u][v]) {
                    dist[v] = dist[u] + w[u][v];
                    parent[v] = u;
                    x = v;
                }
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
    } else {
        // восстановление цикла
        int y = x;
        for (int i = 0; i < N; i++) y = parent[y];

        vector<int> cycle;
        int cur = y;
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while (cur != y);
        cycle.push_back(y);
        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";
        cout << cycle.size() << "\n";
        for (int v : cycle) cout << v << " ";
    }

    return 0;
}