#include <iostream>
#include <deque>
using namespace std;

int main(){
    deque<int> d;
    char c;
    while(cin >> c){
        if(c=='!'){
            break;
        }
        else if(c=='+'){
            int x; cin >> x;
            d.push_front(x);
        }
        else if(c=='-'){
            int x; cin >> x;
            d.push_back(x);
        }
        else if(c=='*'){
            if(d.empty()){
                cout << "error" << endl;
            }
            else if(d.size() == 1){
                cout << d.front() + d.back() << endl;
                d.pop_front();
            }
            else{
                cout << d.front() + d.back() << endl;
                d.pop_front(); d.pop_back();
            }
        }
    }
    return 0;
}
