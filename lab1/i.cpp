#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    queue<int> qS, qK;
    for(int i=0; i<n;i++){
        if(s[i]=='S') qS.push(i);
        else qK.push(i);
    }
    while(!qS.empty() && !qK.empty()){
        int sPos = qS.front(); 
        int kPos = qK.front();
        if(sPos < kPos){
            qK.pop();
            qS.push(sPos + n);
            qS.pop();
        }
        else{
            qS.pop();
            qK.push(kPos + n);
            qK.pop();
        }
    }
    if(qS.empty()) cout << "KATSURAGI" << endl;
    else cout << "SAKAYANAGI" << endl;
    
    return 0;
}