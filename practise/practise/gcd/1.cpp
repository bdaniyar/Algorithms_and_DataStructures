#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int gcd2(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main() {
    int a = 30, b = 21;
    cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << endl;
    return 0;
}

int gcd(int a,int b){
    while(b!=0){
        int temp = b;
        b = a % a;
        a = temp;
    }
    return a;
}



long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}


bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}