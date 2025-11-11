#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int k = 3;
    vector<vector<int>> arr(n, vector<int>(k));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> arr[i][j];
        }
    }

    int ka = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum += arr[i][j];
        }
        if (sum >= 2) {
            ka++;
        }
    }

    cout << ka;
}