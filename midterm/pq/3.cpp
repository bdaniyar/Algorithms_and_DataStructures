#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n; cin >> n;
    priority_queue<int> pq;
    int k; cin >> k;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        pq.push(x);
    }
    int count = 0;

    while(k--){
        int cur = pq.top(); pq.pop();
        pq.push(cur-1);
        count+=cur;
    }
    cout << count << endl;

    return 0;
}