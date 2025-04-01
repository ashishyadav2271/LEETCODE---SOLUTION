class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }
        curr = head;
        while (curr) {
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }
        Node* newHead = head->next;
        curr = head;
        while (curr) {
            Node* clone = curr->next;
            curr->next = clone->next;
            if (clone->next) clone->next = clone->next->next;
            curr = curr->next;
        }
        return newHead;
    }
};
