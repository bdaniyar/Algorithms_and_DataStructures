#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    queue<int> q1;
    queue<int> q2;
    for(int i=0; i<5; i++){
        int x; cin >> x;
        q1.push(x);
    }
    for(int i=0; i<5; i++){
        int x; cin >> x;
        q2.push(x);
    }
    int steps = 0;
    while(!q1.empty() && !q2.empty()){
        int x1 = q1.front(); q1.pop();
        int x2 = q2.front(); q2.pop();

        // special rule: 0 beats 9
        if (x1 == 0 && x2 == 9) {
            q1.push(x1);
            q1.push(x2);
        } else if (x1 == 9 && x2 == 0) {
            q2.push(x1);
            q2.push(x2);
        } else if (x1 > x2) {
            // Boris wins: push Boris' card then Nursik's card
            q1.push(x1);
            q1.push(x2);
        } else {
            // Nursik wins (x2 > x1): still push Boris' card then Nursik's card
            q2.push(x1);
            q2.push(x2);
        }

        steps++;
        if(steps > 1000000){
            cout << "blin nichya" << endl;
            return 0;
        }
    }
    if(q1.empty()) cout << "Nursik " << steps << endl;
    else cout << "Boris " << steps << endl;
    return 0;
}