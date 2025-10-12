#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    long long n, x;
    cin >> n >> x;
    long long sum = 0;
    long long isum = 0;
    for(long long i=0;i<n;i++){
        string s;
        cin >> s;
        if(s=="print"){
            cout << sum << endl;
        }
        else if(s == "insert") {
            long long k;
            cin >> k;
            if (pq.size() < x) {
                pq.push(k);
                sum += k;
            } else if (k > pq.top()) {
                sum -= pq.top();
                pq.pop();
                pq.push(k);
                sum += k;
            }
        }
    }
}