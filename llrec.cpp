#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void attachNode(Node*& list, Node*& node) {
    node->next = list;
    list = node;
}

void llpivotHelper(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == nullptr) {
        return;
    }

    Node* currentNode = head;
    head = head->next; 
    currentNode->next = nullptr; 

    if (currentNode->val <= pivot) {
        attachNode(smaller, currentNode);
    } else {
        attachNode(larger, currentNode);
    }

    llpivotHelper(head, smaller, larger, pivot);
}

void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    // Base case: End of the list
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    // Detach the current node from the list
    Node* current = head;
    head = head->next;
    current->next = nullptr;

    // Recursive call to process the rest of the list
    llpivot(head, smaller, larger, pivot);

    // Attach current node to the appropriate list based on its value
    if (current->val <= pivot) {
        current->next = smaller;
        smaller = current;
    } else {
        current->next = larger;
        larger = current;
    }
}
