#include <bits/stdc++.h>
using namespace std;

struct P {
    long long x, y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<P> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].x >> a[i].y;

    if (n == 1) {
        cout << 0;
        return 0;
    }

    auto can = [&](long long W) {
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u = 0; u < n; u++) {
                if (!vis[u]) {
                    long long d = llabs(a[v].x - a[u].x) + llabs(a[v].y - a[u].y);
                    if (d <= W) {
                        vis[u] = 1;
                        q.push(u);
                    }
                }
            }
        }
        return vis[n - 1];
    };

    long long L = 0, R = 2e9, ans = R;

    while (L <= R) {
        long long mid = (L + R) / 2;
        if (can(mid)) {
            ans = mid;
            R = mid - 1;
        } else {
            L = mid + 1;
        }
    }

    cout << ans;
    return 0;
}