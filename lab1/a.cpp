#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i); 

        vector<int> ans(n);
        for (int x = 1; x <= n; x++) {
            for (int t = 0; t < x; t++) {
                q.push(q.front());
                q.pop();
            }
            int pos = q.front();
            q.pop();
            ans[pos] = x;
        }

    
        for (int i = 0; i < n; i++) {
            cout << " ";
            cout << ans[i];
        }
        cout << endl;
    }
}
