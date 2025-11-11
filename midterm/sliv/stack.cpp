#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n; cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        string s; cin >>s;
        if(s=="add"){
            int x; cin >> x;
            st.push(x);
        }
        else if(s=="delete"){
            st.pop();
        }
        else if(s=="getmax"){
            stack<int> st2 = st;
            int max = INT_MIN;
            while(!st2.empty()){
                if(st2.top() > max){
                    max = st2.top();
                }
                st2.pop();
            }
            cout << max << endl;
        }
        else if(s=="getcur"){
            if(st.empty()) cout << "error";
            else cout << st.top();
        }
    }
    return 0;
}