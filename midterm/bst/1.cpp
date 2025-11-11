#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    map<int, pair<int,int>> child;
    int root = a[0];

    // Строим BST
    for (int i = 1; i < n; i++) {
        int cur = root;
        while (true) {
            if (a[i] < cur) {
                if (child[cur].first == 0) { // нет левого
                    child[cur].first = a[i];
                    break;
                }
                cur = child[cur].first;
            } else {
                if (child[cur].second == 0) { // нет правого
                    child[cur].second = a[i];
                    break;
                }
                cur = child[cur].second;
            }
        }
    }

    // Проверяем пути
    while (m--) {
        string s;
        cin >> s;
        int cur = root;
        bool ok = true;
        for (char c : s) {
            if (c == 'L') cur = child[cur].first;
            else cur = child[cur].second;
            if (cur == 0) { ok = false; break; }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}