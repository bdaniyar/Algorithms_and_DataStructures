#include <iostream>
#include <vector>
using namespace std;

// ========================== Merge для возрастания ==========================
void mergeAscending(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j])  // сравнение для ASC
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int p = 0; p < temp.size(); p++)
        arr[left + p] = temp[p];
}

void mergeSortAscending(vector<int> &arr, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortAscending(arr, left, mid);
    mergeSortAscending(arr, mid + 1, right);
    mergeAscending(arr, left, mid, right);
}

// ========================== Merge для убывания ==========================
void mergeDescending(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;

    while(i <= mid && j <= right) {
        if(arr[i] >= arr[j])  // сравнение для DESC
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while(i <= mid) temp[k++] = arr[i++];
    while(j <= right) temp[k++] = arr[j++];

    for(int p = 0; p < temp.size(); p++)
        arr[left + p] = temp[p];
}

void mergeSortDescending(vector<int> &arr, int left, int right) {
    if(left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortDescending(arr, left, mid);
    mergeSortDescending(arr, mid + 1, right);
    mergeDescending(arr, left, mid, right);
}

// ========================== Main ==========================
int main() {
    vector<int> arr1 = {38, 27, 43, 3, 9, 82, 10};

    // Сортировка по возрастанию
    mergeSortAscending(arr1, 0, arr1.size() - 1);
    cout << "Ascending: ";
    for(int x : arr1) cout << x << " ";
    cout << endl;

    vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};

    // Сортировка по убыванию
    mergeSortDescending(arr2, 0, arr2.size() - 1);
    cout << "Descending: ";
    for(int x : arr2) cout << x << " ";
    cout << endl;
}