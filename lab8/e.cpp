#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> hash_values(n);
    for (int i = 0; i < n; i++) {
        cin >> hash_values[i];
    }

    vector<long long> power(55, 1);
    for (int i = 1; i < 55; i++) {
        power[i] = power[i - 1] * 2;
    }

    string result;
    result.reserve(n);

    for (int i = 0; i < n; i++) {
        long long cur_value;
        if (i == 0)
            cur_value = hash_values[i] + 97;  // первый символ
        else
            cur_value = (hash_values[i] - hash_values[i - 1]) / power[i] + 97;

        result.push_back(static_cast<char>(cur_value));
    }

    cout << result << "\n";
    return 0;
}