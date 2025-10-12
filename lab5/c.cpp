#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    long long n,m;
    priority_queue<int> pq;
    cin >> n >> m;
    for(long long i=0;i<n;i++){
        long long x; cin >> x;
        pq.push(x);
    }
    long long sum = 0;
    for(long long i=0;i<m;i++){
        sum+= pq.top();
        pq.push(pq.top()- 1); pq.pop();

    }
    cout << sum << endl;
}