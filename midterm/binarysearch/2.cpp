#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int left = 0, right = n-1;
    int target; cin >> target;
    int first= -1, last = -1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(v[mid] == target){
            first = mid;
            right = mid -1;
        }
        else if(v[mid] > target){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }
    left = 0; right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(v[mid] == target){
            last = mid;
            left = mid +1;
        }
        else if(v[mid] > target){
            right = mid -1;
        }
        else{
            left = mid + 1;
        }
    }

    cout << first << " " << last << endl;


    return 0;
}