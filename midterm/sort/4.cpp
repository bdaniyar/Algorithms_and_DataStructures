#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore(); // убрать \n после числа

    for (int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<string> v;
        string word;

        while (ss >> word) {
            v.push_back(word);
        }

        stable_sort(v.begin(), v.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for (auto &x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}