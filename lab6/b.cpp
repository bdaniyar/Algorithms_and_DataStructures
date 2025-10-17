#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    vector<int> vecta(a);
    vector<int> vectb(b);

    for (int i = 0; i < a; i++) cin >> vecta[i];
    for (int j = 0; j < b; j++) cin >> vectb[j];

    vector<int> fvect; 
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if (vecta[i] == vectb[j]) {
                fvect.push_back(vecta[i]);
                vectb[j] = -1e9; 
                break; 
            }
        }
    }
    sort(fvect.begin(), fvect.end());

   
    for (int x : fvect) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}