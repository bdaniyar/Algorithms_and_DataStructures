#include <iostream>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x; cin >> x;
        if(x==1){
            int c; cin >> c;
            v.push_back(c);
        }
        else if(x==2){
            reverse(v.begin(), v.end());
        }
    }

    for(int x: v){
        cout << x << " ";
    }


    return 0;
}