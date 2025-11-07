#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll base1 = 31;
const ll base2 = 37;

struct DoubleHash {
    vector<ll> h1, h2, p1, p2;
    int n;
    DoubleHash(const string &s) {
        n = s.size();
        h1.resize(n+1, 0);
        h2.resize(n+1, 0);
        p1.resize(n+1, 1);
        p2.resize(n+1, 1);
        for (int i = 1; i <= n; i++) {
            h1[i] = (h1[i-1] * base1 + (s[i-1]-'a'+1)) % mod1;
            h2[i] = (h2[i-1] * base2 + (s[i-1]-'a'+1)) % mod2;
            p1[i] = (p1[i-1] * base1) % mod1;
            p2[i] = (p2[i-1] * base2) % mod2;
        }
    }
    pair<ll,ll> get(int l, int r) {
        ll x1 = (h1[r] - h1[l-1] * p1[r-l+1]) % mod1;
        ll x2 = (h2[r] - h2[l-1] * p2[r-l+1]) % mod2;
        if (x1 < 0) x1 += mod1;
        if (x2 < 0) x2 += mod2;
        return {x1, x2};
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;

    vector<string> s(k);
    for (int i = 0; i < k; i++) cin >> s[i];

    vector<DoubleHash> hashes;
    for (int i = 0; i < k; i++)
        hashes.emplace_back(s[i]);

    int n = s[0].size();
    string answer = "";

    int low = 1, high = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        unordered_set<uint64_t> common;


        for (int i = 1; i + mid - 1 <= s[0].size(); i++) {
            auto h = hashes[0].get(i, i+mid-1);
            uint64_t val = ((uint64_t)h.first << 32) ^ h.second;
            common.insert(val);
        }

        bool ok = true;
        for (int i = 1; i < k; i++) {
            unordered_set<uint64_t> cur;
            for (int j = 1; j + mid - 1 <= s[i].size(); j++) {
                auto h = hashes[i].get(j, j+mid-1);
                uint64_t val = ((uint64_t)h.first << 32) ^ h.second;
                cur.insert(val);
            }
         
            unordered_set<uint64_t> next;
            for (auto &x : common)
                if (cur.count(x)) next.insert(x);
            common = move(next);
            if (common.empty()) { ok = false; break; }
        }

        if (ok) {
            auto h = *common.begin();
            for (int i = 0; i + mid <= s[0].size(); i++) {
                auto hh = hashes[0].get(i+1, i+mid);
                uint64_t val = ((uint64_t)hh.first << 32) ^ hh.second;
                if (val == h) {
                    answer = s[0].substr(i, mid);
                    break;
                }
            }
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << answer;
}