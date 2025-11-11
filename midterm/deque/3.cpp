#include <iostream>
#include <deque>

using namespace std;

int main(){
    deque<int> dq = {3, 7, 2, 9, 5};
    int maxval = INT_MIN;
    for(int i=0;i<dq.size();i++){
        if(dq[i] > maxval){
            maxval =dq[i];
        }
    }
    cout << maxval << endl;
    int maxval2 = INT_MIN;
    dq.pop_back(); dq.pop_front();
    for(int i=0;i<dq.size();i++){
        if(dq[i] > maxval2){
            maxval2=dq[i];
        }
    }
    cout << maxval2<< endl;
    return 0;
}

int main2() {
    deque<int> dq = {3, 7, 2, 9, 5};

    cout << *max_element(dq.begin(), dq.end()) << endl;

    dq.pop_front();
    dq.pop_back();

    cout << *max_element(dq.begin(), dq.end()) << endl;

    return 0;
}