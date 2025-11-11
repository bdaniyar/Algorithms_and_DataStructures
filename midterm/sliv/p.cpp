#include <iostream>
#include <vector>
using namespace std;
// problem b
bool is_prime(int x) {
    if (x < 2) return false;               
    for (int i = 2; i * i <= x; i++) {     
        if (x % i == 0)
            return false;
    }
    return true;
}

int main(){
    int n ; cin >> n;
    for(int p=4;p<=n;p++){
        if(is_prime(p)){
            int q = n-p;
            if(is_prime(q)){
                cout << p << " " << q << endl;
                return 0;
            }
        }
    }

    return 0;
}