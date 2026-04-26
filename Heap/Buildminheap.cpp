#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // Min Heap ke liye comparison reverse
    if (left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }

    if (right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }

    if (smallest != i) {
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

vector<int> buildMinHeap(vector<int> &arr) {
    int n = arr.size();

    // last non-leaf node se start
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    return arr;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    // input lena
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // heap build
    buildMinHeap(arr);

    // output print
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}