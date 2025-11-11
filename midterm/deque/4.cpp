#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n; cin >> n;
    deque<int> dq;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        dq.push_back(x);
    }
    deque<int> dq1 = dq;
    for(int i=0;i<n;i++){
        cout << dq1.back() << " ";
        dq1.pop_back();
    }

    return 0;
}