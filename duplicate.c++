class Solution {
    public:
      Node* removeDuplicates(Node* head) {
          Node* curr = head;
          while (curr != nullptr && curr->next != nullptr) {
              if (curr->data == curr->next->data) {
                  Node* temp = curr->next;
                  curr->next = curr->next->next;
                  delete temp;
              } else {
                  curr = curr->next;
              }
          }
          return head;
      }
  };