#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    sort(vect.begin(), vect.end(),[](
        const int&a, const int&b){
            if((a%2==0) && (b%2!=0)) return true;
            if((a%2 !=0) && (b%2 == 0)) return false;
            return a < b;
        });

    
    // 

    return 0;
}