/*
Node is defined as:
class Node{
  public:
  int data;
  Node* next;
  Node(int data){
      this->data = data;
      this->next = nullptr;
  }
}
*/
int solve(Node* head){
    if (!head || !head->next || !head->next->next) {
        return 0;
    }
    int criticalPoints = 0;
    Node* prev = head;
    Node* curr = head->next;
    Node* next = head->next->next;
    while (next) {
        if ((curr->data > prev->data && curr->data > next->data) ||
            (curr->data < prev->data && curr->data < next->data)) {
            criticalPoints++;
        }
        prev = curr;
        curr = next;
        next = next->next;
    }
    return criticalPoints;
}