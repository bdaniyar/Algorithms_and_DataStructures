#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    bool is_prime = true;

    if (n < 2)
        is_prime = false;
    else {
        for (int i = 2; i*i <= n; i++) {
            if (n % i == 0) {
                is_prime = false;
                break;
            }
        }
    }

    if (is_prime)
        cout << n << " is a prime number\n";
    else
        cout << n << " is not a prime number\n";
}