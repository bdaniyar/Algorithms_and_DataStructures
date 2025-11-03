#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> rows(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> rows[i][j];
        }
    }
    sort(rows.begin(), rows.end(), [](const vector<int> &a, const vector<int> &b) {
        int sumA = 0, sumB = 0;
        for (int x : a) sumA += x;
        for (int x : b) sumB += x;

        if (sumA != sumB)
            return sumA > sumB; // по убыванию суммы
        return a < b;           // по возрастанию лексикографически
    });

    for (auto &row : rows) {
        for (int x : row) cout << x << " ";
        cout << endl;
    }
    return 0;
}