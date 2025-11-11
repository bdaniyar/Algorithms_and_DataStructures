#include <iostream>
#include <vector>
using namespace std;

// Функция построения LPS (Longest Prefix Suffix)
vector<int> build_lps(const string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; // длина текущего совпадающего префикса
    int i = 1;

    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// Проверка: содержится ли pattern в text с помощью KMP
bool kmp_search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) return true; // нашли подстроку
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string A, B;
    cin >> A >> B;

    // Если B уже содержится в A
    if (A.find(B) != string::npos) {
        cout << 1;
        return 0;
    }

    string repeated = A;
    int count = 1;

    // Повторяем A, пока длина не >= длины B
    while ((int)repeated.size() < (int)B.size()) {
        repeated += A;
        count++;
    }

    // Проверяем текущую строку и плюс одно повторение (чтобы покрыть смещение)
    if (kmp_search(repeated, B)) {
        cout << count;
        return 0;
    }

    repeated += A;
    count++;

    if (kmp_search(repeated, B)) {
        cout << count;
        return 0;
    }

    cout << -1;
    return 0;
}