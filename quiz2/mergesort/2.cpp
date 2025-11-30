#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arr, int left, int mid, int right){
    vector<int> temp(right - left +1);
    int i = left;
    int j = mid +1;
    int k = 0;
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }
    while(i <= mid) temp[k++] = arr[i++];
    while(j<= right) temp[k++] = arr[j++];

    for(int p=0;p< temp.size();p++){
        arr[left+p] = temp[p];
    }
}

void mergesort(vector<int> &arr, int left, int right){
    if(left>= right) return;
    int mid = left + (right - left)/2;
    mergesort(arr, left, mid);
    mergesort(arr, mid+1, right);
    merge(arr, left, mid, right);
}


void merge1(vector<int> &arr, int left, int mid, int right){
    vector<int> temp(right - left+1);
    int i = left;
    int j = mid +1;
    int k = 0;
    while(i<=mid && j<=right){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }
        else{
            temp[k++] = arr[j++];
        }
    }

    while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];

    for(int p=0;p<temp.size();p++){
        arr[left+p] = temp[p];
    }
}

void mergesort1(vector<int> &arr, int left, int right){
    if(left >= right) return ;
    int mid = (left + (right - left)/2);
    mergesort1(arr, left, mid);
    mergesort1(arr, mid+1, right);
    merge1(arr, left, mid, right);
}