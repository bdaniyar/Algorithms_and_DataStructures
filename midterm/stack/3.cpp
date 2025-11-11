#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>
using namespace std;

// вывести макс знач

int main(){
    stack<int> st;
    st.push(50);
    st.push(10);
    st.push(20);
    st.push(40);
    
    int max = st.top();
    stack<int> temp = st;
    while(!temp.empty()){
        if(temp.top() > max) max = temp.top();
        temp.pop();
    }
    cout << max << endl;

    return 0;
}