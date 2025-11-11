#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(0);
    dq.push_front(-1);
    dq.pop_back();
    dq.pop_front();

    for(int i=0;i<dq.size();i++){
        cout << dq[i] << " ";
        if (i != dq.size() - 1) cout << " ";
    }
    cout << endl;

    return 0;
}