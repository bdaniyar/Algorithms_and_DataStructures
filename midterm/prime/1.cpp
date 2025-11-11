#include <iostream>

using namespace std;


bool is_prime(int x){
    if(x <2) return false;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n; cin >> n;
    int cnt_alp = 0;
    for(int i=2;i<=n;i++){
        int cnt = 0;

        for(int p=2;p<=i;p++){
            if(i%p==0 && is_prime(p)){
                cnt++;
            }
        }
        if(cnt==2) cnt_alp ++;
    }

    cout << cnt_alp << endl;
    return 0;
}