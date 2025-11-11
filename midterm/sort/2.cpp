#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    sort(vect.begin(), vect.end(), [](const int&a, const int&b){
        return a > b;
    });
    for(int x: vect){
        cout << x << " ";
    }


    return 0;
}