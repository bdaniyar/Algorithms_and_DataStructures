#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        int l; cin >> l;
        int k; cin >> k;
        vector<int> v(l);
        for(int j=0;j<l;j++){
            cin >> v[j];
        }
        int maxval = 0;
        for(int j=0;j<l+1-k;j++){
            maxval = *max_element(v.begin()+j, v.begin()+j+k);
            cout << maxval << " ";
        }
        cout << endl;
    }

    return 0;
}