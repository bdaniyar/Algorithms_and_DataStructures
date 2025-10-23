#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> result;
    set_intersection(a.begin(), a.end(),
                     b.begin(), b.end(),
                     back_inserter(result));

    for (int x : result) cout << x << " ";

    return 0;
}

// 	•	sort() — сортирует оба массива, чтобы можно было эффективно искать общие элементы.
//	•	set_intersection() — берёт два отсортированных диапазона и кладёт в result элементы, которые есть в обоих (включая повторяющиеся).
//	•	back_inserter(result) — добавляет найденные элементы в конец result.