#include <iostream>
#include <vector>

using namespace std;

int n, cnt;
vector<bool> prime(100005, 1);
vector<int> v;

int main(){
    
    cin >> n;
    
    prime[0] = prime[1] = 0;
    
    for(int i = 2; i <= 100000; i++){
        if(prime[i])
            if(i * 1ll * i <= 100000)
                for(int j = i * i; j <= 100000; j += i) //making them false if its not prime numbers
                    prime[j] = 0;
    }
    
    for(int i = 2; i <= 100000; i++){
        if(prime[i]) v.push_back(i);
    }
    
    for(int i = 2; i <= 100000; i++){
        if(prime[i]) cnt++;
        if(cnt == n){
            cout << v[i - 1]; // finding the nth prime number
            return 0;
        }
    }
    
    return 0;
}