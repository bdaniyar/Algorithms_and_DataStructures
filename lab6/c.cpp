#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    long long n; cin >> n;
    vector<long long> vect(n);
    for(long long i=0;i<n;i++){
        cin >> vect[i];
    }
    sort(vect.begin(), vect.end());
    long long minval = LLONG_MAX;
    for(long long i=1;i<n;i++){
        minval = min(minval, abs(vect[i] - vect[i-1]));
    }
    for(long long i=1;i<n;i++){
        if(abs(vect[i] - vect[i-1]) == minval){
            cout << vect[i-1] << " " << vect[i] << " ";
        }
    }
    cout << endl;
    return 0;
}