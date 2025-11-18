#include <iostream>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    int n = text.size();
    int m = pattern.size();

    int d = 256;       // размер алфавита
    int q = 101;       // простое число (модуль)

    vector<int> result;

    if (m > n) return result;

    int h = 1;
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    int p = 0; // hash(pattern)
    int t = 0; // hash(text window)

    // 1) хешируем pattern и первое окно
    for (int i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    // 2) скользящее окно
    for (int i = 0; i <= n - m; i++) {

        // если хеши совпали → проверяем символы
        if (p == t) {
            if (text.substr(i, m) == pattern)
                result.push_back(i);
        }

        // 3) вычисляем хеш следующего окна
        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }

    return result;
}

int main() {
    string text = "ababcabcabababd";
    string pattern = "abab";

    vector<int> pos = rabinKarp(text, pattern);

    for (int index : pos)
        cout << index << " ";
}