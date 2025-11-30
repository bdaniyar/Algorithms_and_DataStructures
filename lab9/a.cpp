#include <iostream>
#include <vector>
using namespace std;


vector<int> build_lps(const string &pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0; 
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


bool kmp_search(const string &text, const string &pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> lps = build_lps(pattern);
    int i = 0, j = 0;

    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
            if (j == m) return true; 
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

    if (A.find(B) != string::npos) {
        cout << 1;
        return 0;
    }

    string repeated = A;
    int count = 1;

    while ((int)repeated.size() < (int)B.size()) {
        repeated += A;
        count++;
    }
    
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