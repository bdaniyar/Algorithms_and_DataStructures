#include <iostream>

using namespace std;

int binary_search(int a[], int n, int x){
    int left = 0;
    int right = n-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(a[mid] == x){
            return mid;
        }
        else if(a[mid] < x){
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    return -1;
}