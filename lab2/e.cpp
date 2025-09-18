#include <iostream>
#include <map>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, int> mp;
    for(int i=0;i<n;i++){
        string s; cin >> s;
        mp[s]++;
    }
    cout << "All in all: " << mp.size() << endl;
    cout << "Students: " << endl;
    for(auto k:mp){
        cout << k.first << endl;
    }
} 