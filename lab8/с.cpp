#include <bits/stdc++.h>
using namespace std;

const long long P = 131; 
const long long MOD = 1e9 + 7;


vector<long long> prefix_hash(const string &s, vector<long long> &power) {
    int n = s.size();
    vector<long long> h(n + 1, 0);
    power[0] = 1;
    for (int i = 0; i < n; i++) {
        h[i + 1] = (h[i] * P + s[i]) % MOD;
        power[i + 1] = (power[i] * P) % MOD;
    }
    return h;
}

long long get_hash(const vector<long long> &h, const vector<long long> &power, int l, int r) {
    long long res = (h[r + 1] - (h[l] * power[r - l + 1]) % MOD + MOD) % MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n;
    cin >> n;

    vector<string> tapes(n);
    for (int i = 0; i < n; i++) cin >> tapes[i];

    int N = S.size();
    vector<long long> power(N + 1);
    vector<long long> H = prefix_hash(S, power);

   
    unordered_map<int, vector<long long>> small_hashes;

    for (auto &t : tapes) {
        vector<long long> pwr(t.size() + 1);
        auto ht = prefix_hash(t, pwr);
        long long val = get_hash(ht, pwr, 0, t.size() - 1);
        small_hashes[t.size()].push_back(val);
    }

    vector<bool> covered(N, false);


    for (auto &[len, hashes] : small_hashes) {
        if (len > N) continue;
        for (int i = 0; i + len <= N; i++) {
            long long h_sub = get_hash(H, power, i, i + len - 1);
            for (auto val : hashes) {
                if (h_sub == val) {
                    for (int j = i; j < i + len; j++)
                        covered[j] = true;
                    break;
                }
            }
        }
    }

    bool ok = all_of(covered.begin(), covered.end(), [](bool x){ return x; });

    cout << (ok ? "YES\n" : "NO\n");
    return 0;
}