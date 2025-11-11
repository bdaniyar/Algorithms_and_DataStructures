#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> heap;

    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        heap.push_back(x);
        push_heap(heap.begin(), heap.end()); // вставка с сохранением max-heap
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;
        if (right < n) { // есть оба сына
            if (heap[right] > heap[left]) count++;
        }
    }

    cout << count << endl;
}