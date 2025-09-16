#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) cin >> words[i];

    k = k % n; 
    for (int i = 0; i < n; ++i) {
        cout << words[(i + k) % n] << " ";
    }
    cout << endl;

    return 0;
}