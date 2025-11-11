#include <iostream>

using namespace std;

int main(){
    int m,n;
    cin >> m >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(vect[i]+vect[j] == m){
                cout << vect[i] << " " << vect[j] << endl;
                return 0;
            }
        }
    }

    return 0;
}