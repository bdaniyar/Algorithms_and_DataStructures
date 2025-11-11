#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        // Убираем все пинги, которые старше 3000 миллисекунд
        while (!q.empty() && q.front() < t - 2999) {
            q.pop();
        }

        // Добавляем текущий пинг
        q.push(t);

        // Размер очереди = количество пингов за последние 3000 мс
        cout << q.size() << " ";
    }

    return 0;
}