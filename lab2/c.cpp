#include <iostream>
#include <list>
using namespace std;
int main() {
    int n; cin >> n;
    list<int> lst;
    for(int i=0; i<n; i++){
        int x ; cin >> x;
        lst.push_back(x);
    }
    auto it = lst.begin();
    int idx = 0;
    while (it != lst.end()) {
        if (idx % 2 == 0) {    
            cout << *it << " ";
        }
        ++it;
        ++idx;
    }
    cout << endl;
    return 0;
}