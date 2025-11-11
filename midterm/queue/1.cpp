#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n; cin >> n;
    queue<int> q;
    while(n--){
        int x; cin >> x;
        if(x==1){
            int s; cin >> s;
            q.push(s);
        }
        else if(x==2){
            q.pop();
        }
        else if(x==3){
            cout << q.front() << endl;
        }
    }
    
    return 0;
}