#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; cin >> n;
    vector<int> vect(n);
    for(int i=0;i<n;i++){
        cin >> vect[i];
    }
    int left = 0;
    int right = n-1;
    int target; cin >> target;
    bool isfound = false;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(vect[mid] == target){
            cout << mid << endl;
            isfound = true;
            break;
        }
        else if(vect[mid] < target){
            left = mid + 1;
        }
        else if(vect[mid] > target){
            right = mid -1;
        }
    }
    if(!isfound){
        cout << "-1" << endl;
    }



    return 0;
}