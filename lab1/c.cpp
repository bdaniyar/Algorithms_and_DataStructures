#include <iostream>
#include <string>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    string resA, resB;
    for (char c : a) {
        if (c == '#') {
            if (!resA.empty()) resA.pop_back();
        } else {
            resA.push_back(c);
        }
    }
    for (char c : b) {
        if (c == '#') {
            if (!resB.empty()) resB.pop_back();
        } else {
            resB.push_back(c);
        }
    }
    if (resA == resB) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}