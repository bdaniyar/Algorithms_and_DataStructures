#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> vect(n);

    for (int i = 0; i < n; i++) {
        cin >> vect[i];
    }

    sort(vect.begin(), vect.end(), [](const string&a, const string&b){
        if(a.size() == b.size()) return a < b;
        return a.size() < b.size(); // по возрастанию
    });
    for (auto &s : vect)
        cout << s << endl;

    return 0;
}