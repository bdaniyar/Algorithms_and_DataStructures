#include <iostream>

using namespace std;

int binary_search(int arr[], int l, int r, int x){
    while(l <=r){
        int m = l + (r-l)/2;
        if(arr[m] == x){
            return m;
        }
        else if(arr[m] < l){
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    return -1;
}

