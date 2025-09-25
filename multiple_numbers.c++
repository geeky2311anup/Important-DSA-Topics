#include <bits/stdc++.h>
using namespace std;

class MaxHeap {
    vector<int> arr;
    
    void bubbleUp(int pos) {
        while (pos > 0) {
            int parent = (pos - 1) / 2;
            if (arr[pos] <= arr[parent]) break;
            
            swap(arr[pos], arr[parent]);
            pos = parent;
        }
    }
    
    void bubbleDown(int pos) {
        int n = arr.size();
        
        while (true) {
            int maxPos = pos;
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            
            if (left < n && arr[left] > arr[maxPos]) {
                maxPos = left;
            }
            if (right < n && arr[right] > arr[maxPos]) {
                maxPos = right;
            }
            
            if (maxPos == pos) break;
            
            swap(arr[pos], arr[maxPos]);
            pos = maxPos;
        }
    }
    
public:
    void add(int val) {
        arr.push_back(val);
        bubbleUp(arr.size() - 1);
    }
    
    void removeTop() {
        if (arr.empty()) return;
        
        arr[0] = arr.back();
        arr.pop_back();
        
        if (!arr.empty()) {
            bubbleDown(0);
        }
    }
    
    int getMax() {
        return arr.empty() ? -1 : arr[0];
    }
};

int main() {
    int n;
    cin >> n;
    
    MaxHeap heap;
    
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        
        if (op == "+") {
            int val;
            cin >> val;
            heap.add(val);
        } else {
            heap.removeTop();
        }
        
        cout << heap.getMax() << "\n";
    }
    
    return 0;
}
