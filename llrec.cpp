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
    if (head == nullptr) {
        smaller = nullptr;
        larger = nullptr;
        return;
    }

    Node* current = head;
    head = head->next;
    current->next = nullptr;

    llpivot(head, smaller, larger, pivot);

    if (current->val <= pivot) {
        current->next = smaller;
        smaller = current;
    } else {
        current->next = larger;
        larger = current;
    }
}
