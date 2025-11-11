#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n ; cin >> n;
    vector<string> vect(n);
    for(int i=0;i<n;i++){
        string s; cin >> s;
        vect[i] = s;
    }
    for(int i=0;i<n;i++){
        stack<char> st;
        bool is_balanced = true;
        for(char&c:vect[i]){
            if(c=='(' or c == '[' or c=='{'){
                st.push(c);
            }
            else{
                if(st.empty()){
                    is_balanced = false;
                    break;
                }
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == ']' && top != '[') ||
                    (c == '}' && top != '{')) {
                    is_balanced = false;
                    break;
                }
            }
        }
        if(!st.empty()){
        is_balanced = false;
        }
        if(is_balanced) cout <<  "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}