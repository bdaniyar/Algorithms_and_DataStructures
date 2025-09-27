#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k; cin >> k;
    int left = 0;
    int right = arr.size() - 1;
    bool isfound = false;
    while(left <= right){
        int mid = left + (right - left)/2;
        if(arr[mid] == k){
            cout << "Yes" << endl;
            isfound = true;
            break;
        }
        else if(arr[mid] < k){
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    if(!isfound){
        cout << "No" << endl;
    }

}