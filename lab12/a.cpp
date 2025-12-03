#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 505;
int adj[MAXN][MAXN];
int x[MAXN]; 
bool active[MAXN]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    for (int i = 1; i <= n; ++i) active[i] = false;

    for (int step = 0; step < n; ++step) {
        int k = x[step]; 
        active[k] = true;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (adj[i][k] + adj[k][j] < adj[i][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }

        int max_dist = 0;
        for (int i = 1; i <= n; ++i) {
            if (!active[i]) continue; 
            for (int j = 1; j <= n; ++j) {
                if (active[j]) {
                    if (adj[i][j] > max_dist) {
                        max_dist = adj[i][j];
                    }
                }
            }
        }

        cout << max_dist << "\n";
    }

    return 0;
}