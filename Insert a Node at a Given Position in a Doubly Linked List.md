# 😏 Is inserting into a Doubly Linked List really this scary? Turns out… not at all 😌

---

## 🎯 Problem Name  
**Insert a Node at a Given Position in a Doubly Linked List**

---

## 🎯 Intuition — what you want to do  
> You are given the `head` of a **doubly linked list**, a position `p`, and a value `x`.  
>  
> Your task is to **insert a new node with value `x` right after position `p`** (0-based indexing as per the traversal logic).  
>  
> Since it’s a **doubly linked list**, you must carefully handle:
> - `next` pointers  
> - `prev` pointers  

The goal is to **insert without breaking the list structure**.

---

## 🎯 What you want to do (high-level goal / why)  
> - Traverse the list until you reach the node at position `p`.  
> - Create a new node with value `x`.  
> - Adjust pointers so that:
>   - The new node comes **after** the current node.
>   - The rest of the list remains intact.
>   - Both `next` and `prev` links stay consistent.

Why careful pointer handling?
> Because one wrong link and the list becomes unusable 😄

---

## 🧠 Why this works  
> - You first move to the correct node (`temp`) where insertion is needed.  
> - You store the original `next` node (`tempPrev`) so it’s not lost.  
> - You link:
>   - `temp → newNode`  
>   - `newNode → tempPrev`  
> - You also fix backward links using `prev`.  
>  
> This preserves the **bidirectional integrity** of the list.

---

## 🔧 Approach (matching your implementation)

### 1) Traverse to position `p`  
> - Start from `head`.  
> - Move forward `p` times using `temp = temp.next`.

---

### 2) Save the next node  
> - Store `temp.next` in `tempPrev`.  
> - This avoids losing the remaining list after insertion.

---

### 3) Insert the new node  
> - Create `new Node(x)`.  
> - Set:
>   - `temp.next` → new node  
>   - `newNode.prev` → `temp`  

---

### 4) Reconnect the remaining list  
> - Point `newNode.next` to `tempPrev`.  
> - If `tempPrev` exists, update `tempPrev.prev` to the new node.

---

### 5) Return head  
> - Head doesn’t change, so just return it.

---

## 🔍 What each pointer update does

### `temp.next = new Node(x)`
> Inserts the new node right after the current node.

### `temp.next.prev = temp`
> Maintains backward link from new node to previous node.

### `temp.next.next = tempPrev`
> Connects new node to the rest of the list.

### `tempPrev.prev = temp.next`
> Fixes backward link of the next node (if it exists).

---

## 🧪 Dry Run (simple example)

List:
1 <-> 2 <-> 4

markdown
Copy code

Insert `x = 3` at `p = 1`

Steps:
- Traverse to node `2`
- Insert `3` after `2`

Result:
1 <-> 2 <-> 3 <-> 4

pgsql
Copy code

All `next` and `prev` pointers remain correct.

---

## 📊 Complexity

> - **Time Complexity:** `O(p)` (traversal to position `p`)  
> - **Space Complexity:** `O(1)` (no extra data structures)

---

## 💻 Code

```java
class Solution {
    Node insertAtPos(Node head, int p, int x) {
        int count = 0;
        Node temp = head;

        // move to the node at position p
        while (count < p) {
            temp = temp.next;
            count++;
        }

        Node tempPrev = temp.next;

        // create and insert new node
        temp.next = new Node(x);
        temp.next.prev = temp;
        temp.next.next = tempPrev;

        // fix backward link of next node if it exists
        if (tempPrev != null) {
            tempPrev.prev = temp.next;
        }

        return head;
    }
}
