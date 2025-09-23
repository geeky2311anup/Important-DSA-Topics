#include <iostream>
#include <string>
#include <vector>

using namespace std;

 // 1. Vector (Dynamic Array)
    vector<int> v = {1, 2, 3, 4, 5};
    v.push_back(6);
    cout << "Vector: ";
    for (int num : v) cout << num << " ";
    cout << endl;

    // 2. Map (Key-Value Pair)
    map<int, string> m;
    m[1] = "One";
    m[2] = "Two";
    m[3] = "Three";
    cout << "Map: ";
    for (auto &pair : m) cout << "{" << pair.first << ", " << pair.second << "} ";
    cout << endl;

    // 3. Set (Unique Elements)
    set<int> s = {4, 2, 7, 1, 2, 7};
    s.insert(5);
    cout << "Set: ";
    for (int num : s) cout << num << " ";
    cout << endl;

    // 4. Queue (FIFO)
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Queue Front: " << q.front() << ", Back: " << q.back() << endl;
    q.pop();
    cout << "Queue Front after pop: " << q.front() << endl;

    // 5. Stack (LIFO)
    stack<int> st;
    st.push(100);
    st.push(200);
    st.push(300);
    cout << "Stack Top: " << st.top() << endl;
    st.pop();
    cout << "Stack Top after pop: " << st.top() << endl;