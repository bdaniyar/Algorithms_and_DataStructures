#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int> pq;
    int n ; cin >> n;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        pq.push(x);
    }
    while(pq.size() > 1){
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        if(a!=b){
            pq.push(abs(a-b));
        }
    }
    cout << pq.top() << endl;

    return 0;
}