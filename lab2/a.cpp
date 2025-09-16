#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int count=100000001;
    int index=0;
    for (int i = 0; i < n; ++i) {
        if(abs(arr[i] - k) < count){
            count = abs(arr[i] - k);
            index = i;
        }
    }
    cout << index << endl;
    return 0;
}