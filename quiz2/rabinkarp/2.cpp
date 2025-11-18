#include <iostream>
#include <vector>
using namespace std;

vector<int> rabinKarp(string text, string pattern) {
    const int d = 256;
    const int q = 101;

    int n = text.size();
    int m = pattern.size();
    vector<int> ans;

    int p = 0, t = 0, h = 1;

    // h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // hash(pattern) и hash(first window)
    for (int i = 0; i < m; i++) {
        p = (p * d + pattern[i]) % q;
        t = (t * d + text[i]) % q;
    }

    // основная логика
    for (int i = 0; i <= n - m; i++) {

        if (p == t) {                     // хеши совпали
            if (text.substr(i, m) == pattern)
                ans.push_back(i);
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;
            if (t < 0) t += q;
        }
    }

    return ans;
}