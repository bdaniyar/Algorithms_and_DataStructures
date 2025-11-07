#include <bits/stdc++.h>
using namespace std;

struct Node {
    int next[26];   
    int link;       // суффиксная ссылка
    vector<int> out; // какие паттерны оканчиваются здесь
    Node() {
        fill(begin(next), end(next), -1);
        link = -1;
    }
};

vector<Node> trie;
vector<int> freq; // количество вхождений каждого паттерна

// Добавление шаблона в trie
void insert(const string &s, int id) {
    int v = 0;
    for (char c : s) {
        int idx = c - 'a';
        if (trie[v].next[idx] == -1) {
            trie[v].next[idx] = trie.size();
            trie.emplace_back();
        }
        v = trie[v].next[idx];
    }
    trie[v].out.push_back(id);
}

// Построение суффиксных ссылок (BFS)
void build_links() {
    queue<int> q;
    for (int c = 0; c < 26; c++) {
        if (trie[0].next[c] != -1) {
            trie[trie[0].next[c]].link = 0;
            q.push(trie[0].next[c]);
        } else {
            trie[0].next[c] = 0;
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int c = 0; c < 26; c++) {
            int u = trie[v].next[c];
            if (u != -1) {
                trie[u].link = trie[trie[v].link].next[c];
                for (int id : trie[trie[u].link].out)
                    trie[u].out.push_back(id);
                q.push(u);
            } else {
                trie[v].next[c] = trie[trie[v].link].next[c];
            }
        }
    }
}

// Поиск в тексте
void search_text(const string &text) {
    int v = 0;
    for (char c : text) {
        v = trie[v].next[c - 'a'];
        for (int id : trie[v].out)
            freq[id]++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        trie.clear();
        trie.emplace_back();
        freq.assign(n, 0);

        vector<string> patterns(n);
        for (int i = 0; i < n; i++) {
            cin >> patterns[i];
            insert(patterns[i], i);
        }

        string text;
        cin >> text;

        build_links();
        search_text(text);

        int mx = *max_element(freq.begin(), freq.end());
        cout << mx << "\n";
        for (int i = 0; i < n; i++) {
            if (freq[i] == mx)
                cout << patterns[i] << "\n";
        }
    }

    return 0;
}