#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    int k; cin >> k;
    int near = INT_MAX;
    int ind = 0;
    for(int i=0;i<n;i++){
        if(abs(vect[i] - k) < near){
            near = abs(vect[i] - k);
            ind = i;
        }
    }
    cout << ind << endl;


    return 0;
}