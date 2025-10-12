#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long n, x;
    cin >> n >> x;
    for (long long i = 0; i < n; i++) {
        long long a;
        cin >> a;
        pq.push(a);
    }

    long long ope = 0;
    while (pq.size() > 1 && pq.top() < x) {
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        pq.push(a + 2*b);
        ope++;
    }

    if (pq.top() >= x) cout << ope << endl;
    else cout << -1 << endl;
}