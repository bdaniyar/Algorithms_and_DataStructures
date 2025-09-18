#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int,int> mp;
    for(int i=0; i<n; i++){
        int x; cin >> x;
        mp[x]++;
    }
    vector<int> v;
    int max = 0;
    for(auto k: mp){
        if(k.second > max){
            max = k.second;
            v.clear();
            v.push_back(k.first);
        }
        else if(k.second == max){
            v.push_back(k.first);
        }
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int x: v) cout << x << " ";
    cout << endl;
    return 0;
}