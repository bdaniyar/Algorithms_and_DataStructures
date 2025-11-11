#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    stack<int> st1, st2, st3;
    int c1 = 0, c2 = 0, c3 = 0;

    int x;
    for(int i=0;i<a;i++) { cin >> x; st1.push(x); c1 += x; }
    for(int i=0;i<b;i++) { cin >> x; st2.push(x); c2 += x; }
    for(int i=0;i<c;i++) { cin >> x; st3.push(x); c3 += x; }

    while(c1 != c2 || c2 != c3){
        int m = max({c1,c2,c3});
        if(m == c1){ c1 -= st1.top(); st1.pop(); }
        else if(m == c2){ c2 -= st2.top(); st2.pop(); }
        else { c3 -= st3.top(); st3.pop(); }
    }

    cout << c1; // или c2, c3 — они равны
}