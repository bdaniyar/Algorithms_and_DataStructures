#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    map<int, pair<int,int>> child;
    int root = vect[0];
    for(int i=1;i<n;i++){
        int cur = root;
        while(true){
            if(vect[i] < cur){
                if(child[cur].first == 0){
                    child[cur].first = vect[i];
                    break;
                }
                cur = child[cur].first;
            }
            else{
                if(child[cur].second == 0){
                    child[cur].second = vect[i];
                    break;
                }
                cur = child[cur].second;
            }
        }
    }
    // pre-order
    int k; cin >> k;
    stack<int> st;
    st.push(k);
    while(!st.empty()){
        int cur = st.top();
        st.pop();
        cout << cur << " ";
        if(child[cur].second != 0){
            st.push(child[cur].second);
        }
        if(child[cur].first != 0){
            st.push(child[cur].first);
        }
    }
    cout << endl;
    return 0;
}