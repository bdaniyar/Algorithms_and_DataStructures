#include <iostream>
#include <queue>
#include <vector>

using namespace std;


int main(){
    priority_queue<long long, vector<long long> , greater<long long>> pq;
    long long n;
    cin >> n;
    for(int i=0;i<n;i++){
        long long x; cin >> x;
        pq.push(x);
    }
    long long val =0;
    while(pq.size() > 1){
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        long long cost = a+b;
        val+=cost;
        pq.push(cost);
    }
    cout << val << endl;
}