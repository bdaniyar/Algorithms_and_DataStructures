#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 +7;
const long long P =131;

vector<long long> prefix_hash(const string&s, vector<long long> &power){
    int n = s.size();
    vector<long long> h(n+1,0);
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

    string s1, s2, p;
    cin >> s1 >> s2 >> p;

    int n = s1.size();
    int m = p.size();

    vector<long long> power(max(n, (int)s2.size()) + 1);
    auto h1 = prefix_hash(s1, power);
    auto h2 = prefix_hash(s2, power);
    auto hp = prefix_hash(p, power);

    long long hash_p = get_hash(hp, power, 0, m - 1);

    int count = 0;
    for (int i = 0; i + m <= n; i++) {
        long long hash1 = get_hash(h1, power, i, i + m - 1);
        long long hash2 = get_hash(h2, power, i, i + m - 1);
        if (hash1 == hash_p && hash2 == hash_p) {
            count++;
        }
    }

    cout << count << "\n";
    return 0;
}