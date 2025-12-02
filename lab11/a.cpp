#include <bits/stdc++.h>
using namespace std;

struct Segment {
    int left, right;
    long long cost;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> start_at(n + 5), end_at(n + 5);

    for (int i = 0; i < m; i++) {
        Segment s;
        cin >> s.left >> s.right >> s.cost;
        start_at[s.left].push_back({s.right, s.cost});
        end_at[s.right].push_back({s.left, s.cost});
    }


    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    long long total_cost = 0;

    for (int vertex = 1; vertex < n; vertex++) {
        for (auto seg : start_at[vertex]) {
            pq.push({seg.second, seg.first});
        }

        while (!pq.empty() && pq.top().second <= vertex) pq.pop();

        if (pq.empty()) {
            cout << "0\n"; 
            return 0;
        }

        total_cost += pq.top().first;
    }

    cout << total_cost << "\n";
    return 0;
}