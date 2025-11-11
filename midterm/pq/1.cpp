#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> pq;
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        pq.push(x);
    }
    int count = 0;
    while(pq.size() > 1){
        int val = 0;
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        val = a+b;
        count += a+b;
        pq.push(val);
    }

    cout << count;

    return 0;
}
