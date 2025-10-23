#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int a,b;
    cin >> a;
    vector<int> vect;
    for(int i=0;i<a;i++){
        int x; cin >> x;
        vect.push_back(x);
    }
    cin >> b;
    for(int i=0;i<b;i++){
        int x; cin >> x;
        vect.push_back(x);
    }
    sort(vect.begin(), vect.end());
    for(int x: vect){
        cout << x << " ";
    }

    return 0;
}