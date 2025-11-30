#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    const int MAXN = 1001;

    vector<vector<int>> a(MAXN, vector<int>(MAXN));
    vector<vector<int>> d(MAXN, vector<int>(MAXN, INT_MAX)); // time of vector

    int cnt = 0;       // mushrooms
    int check = 0;     // how many we killed
    int ans = 0;

    queue<pair<int, int>> q;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];

            if (a[i][j] == 2) {
                q.push({i, j});
                d[i][j] = 0; // time is 0 where mario 
            }

            if (a[i][j] == 1) cnt++;
        }
    }

    int directions[4][2] = {
        {1, 0}, // down
        {-1, 0}, // up
        {0, 1},// right
        {0, -1} // left
    };

    // BFS
    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        for (auto &dir : directions) {
            int nextX = p.first + dir[0]; // We calculate the coordinates of the neighboring cell
            int nextY = p.second + dir[1];

            if (nextX >= 1 && nextX <= m && // граница и если гриб = 1
                nextY >= 1 && nextY <= n &&
                a[nextX][nextY] == 1)
            {
                a[nextX][nextY] = 2; // позицию в марио
                d[nextX][nextY] = d[p.first][p.second] + 1; // время
                ans = max(ans, d[nextX][nextY]); // макс время
                check++;
                q.push({nextX, nextY});
            }
        }
    }

    if (check == cnt) cout << ans;
    else cout << -1;

    return 0;
}