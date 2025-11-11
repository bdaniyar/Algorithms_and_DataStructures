#include <iostream>
#include <cmath>
using namespace std;
// prime count problem
int main() {
    long long n;
    cin >> n;
    int count = 0;

    for (long long i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            count++;
            while (n % i == 0)
                n /= i; // убираем все одинаковые множители
        }
    }

    // если после деления осталось число > 1 — оно само простое
    if (n > 1)
        count++;

    cout << count << endl;
    return 0;
} 