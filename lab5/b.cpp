#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    priority_queue<long long> pq;
    long long n; cin >> n;
    for(int i=0;i<n;i++){
        long long x; cin >> x;
        pq.push(x);
    }
    while(pq.size()>1){
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        if(a!=b){
            pq.push(a-b);
        }
    }
    if(pq.empty()) cout << 0 << endl;
    else cout << pq.top();
}