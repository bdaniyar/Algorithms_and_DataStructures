#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    vector<string> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    rotate(vect.begin(), vect.begin() + k, vect.end());
    k %= n;
    for(int i=0;i<n;i++){
        cout << vect[i] << " ";
    }



    return 0;
}