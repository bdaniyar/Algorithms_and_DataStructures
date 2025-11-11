#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);

    // Создаём копию, чтобы не разрушать оригинал
    stack<int> temp = st;

    cout << "Stack elements (top to bottom): ";
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    return 0;
}