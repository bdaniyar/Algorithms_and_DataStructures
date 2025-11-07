#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const ll base1 = 31;
const ll base2 = 37;

vector<ll> p1, p2, h1, h2;

pair<ll,ll> get_hash(int l, int r) {
    ll x1 = (h1[r] - h1[l-1] * p1[r-l+1]) % mod1;
    ll x2 = (h2[r] - h2[l-1] * p2[r-l+1]) % mod2;
    if (x1 < 0) x1 += mod1;
    if (x2 < 0) x2 += mod2;
    return {x1, x2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    p1.resize(n+1);
    p2.resize(n+1);
    h1.resize(n+1);
    h2.resize(n+1);

    p1[0] = p2[0] = 1;
    for (int i = 1; i <= n; i++) {
        p1[i] = (p1[i-1] * base1) % mod1;
        p2[i] = (p2[i-1] * base2) % mod2;
    }

    for (int i = 1; i <= n; i++) {
        h1[i] = (h1[i-1] * base1 + (s[i-1] - 'a' + 1)) % mod1;
        h2[i] = (h2[i-1] * base2 + (s[i-1] - 'a' + 1)) % mod2;
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;

        pair<ll,ll> target = get_hash(l, r);

        int cnt = 0;
        for (int i = 1; i + len - 1 <= n; i++) {
            if (get_hash(i, i+len-1) == target)
                cnt++;
        }
        cout << cnt << '\n';
    }
}